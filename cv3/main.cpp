#include <iostream>
#include <vector>
#include <map>
#include <openssl/md5.h>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <zconf.h>
#include <wait.h>
#include <thread>
#include <fstream>
#include <algorithm>
#include <mutex>

#define AES_BLOCK_SIZE 16
std::mutex mtx;



void generateWords(std::vector<std::string> &words, int lenght=4){
    int escFlag=0;
    std::string tmp;
    std::vector<int> one;
    for (int i = 0; i < lenght; ++i) {
        one.push_back(0);
    }

    int cnt=0;
    while (true){
///////////////////////////////////////////////kontrola "preteceni" do vyssikho radu////////////////////////////////////
        for (int i = one.size(); i>=0 ; --i) {
            if (one[i]>25){
                one[i]=0;
                one[i-1]+=1;
            }
        }
/////////////////////////////////////////////////generovani retezce/////////////////////////////////////////////////////
        for (int i = 0; i < lenght; ++i) {
            tmp+=(char)(one[i]+97);
        }

        words.push_back(tmp);
//        std::cout<<tmp<<std::endl;
        tmp="";
///////////////////////////////////////////////kontrola konce///////////////////////////////////////////////////////////
        for (int i : one) {
            if (i==25) {
                ++cnt;
            }
        }
        if (cnt==lenght) {
            break;
        }
        cnt=0;
        one[lenght-1]+=1;

    }
    one.clear();
}

void makeHashes(std::vector<std::string> &words, std::map<std::string, std::string> &final){
    unsigned char hashedWord[AES_BLOCK_SIZE];

    for (auto & word : words) {
        std::stringstream s;
        MD5((unsigned char*)word.c_str(), strlen(word.c_str()), (unsigned char *) &hashedWord);
        for (unsigned char j : hashedWord) {
            s << std::hex << std::setw(2) << std::setprecision(2) << (unsigned int)j;
        }
        final[word]=s.str();
    }
}

void makeHashes1(std::vector<std::string> &words, int numberOfParts, int part, std::map<std::string, std::string> &final){                  //std::map<std::string, std::string>
//    std::cout<<numberOfParts << " : "<< part<<std::endl;

    unsigned char hashedWord[AES_BLOCK_SIZE];

    for (int i = (int)(floor((double)words.size()/numberOfParts*part)); i < (int)(floor((double)words.size()/numberOfParts*(part+1))); ++i) {
        std::stringstream s;
        MD5((unsigned char *) words[i].c_str(), strlen(words[i].c_str()), (unsigned char *) &hashedWord);
        for (unsigned char j : hashedWord) {
            s << std::hex << std::setw(2) << std::setprecision(2) << (unsigned int) j;
        }
        mtx.lock();
        final[words[i]] = s.str();
        mtx.unlock();
    }
}

void printMap(std::map<std::string, std::string>& wordMap){
    for(auto & it : wordMap){
        std::cout << it.first << " " << it.second  << "\n";
    }
}
std::map<std::string, std::string> threadController(std::vector<std::string> &words, int numberOfThreads){
    std::map<std::string, std::string> final;
    std::vector<std::thread> threads;
//    std::cout<<"velikost"<<final.max_size()<<std::endl;
    for (int i = 0; i < numberOfThreads; ++i) {
        threads.push_back(std::thread(makeHashes1, std::ref(words), numberOfThreads,i,  std::ref(final)));

    }
    for (auto & thread : threads) {
        if (thread.joinable()){
            thread.join();
        }
    }

    return final;
}

void makeCSV(std::vector<std::string> &words){
    std::chrono::steady_clock sc;
    std::map<std::string, std::string> unneededResult;
    for (int i = 1; i < 6; ++i) {
        std::string fileName;
        fileName.push_back((char)i+48);
        fileName.append("znaky.csv");
//        std::cout<<fileName<<std::endl;
        std::ofstream output;
        output.open(fileName);
        output<<"THREADS\tTIME\n";
        generateWords(words, i);
        for (int j = 1; j < 100; ++j) {
            auto start=sc.now();
            unneededResult=threadController(words, j);
            auto end=sc.now();
            auto time_span = static_cast<std::chrono::duration<double>>(end - start);
            output<<j <<"\t"<<time_span.count()<<std::endl;
            unneededResult.clear();
        }
        output.close();
        words.clear();


    }
}


int main() {
    std::vector<std::string> words;
    std::map<std::string, std::string> hashMap;
//    generateWords(words, 3);
//    hashMap=threadController(words, 7);
//    hashMap=makeHashes(words, 10, 0);
//    printMap(hashMap);
//    hashMap.clear();
//    words.clear();
//hashMap= threadController(words, 10);
//    std::cout<< hashMap.size();
    makeCSV(words);
    return 0;
}
