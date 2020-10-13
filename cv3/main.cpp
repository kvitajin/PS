#include <iostream>
#include <vector>
#include <map>
#include <openssl/md5.h>
#include <iomanip>
#include <cstring>

#define AES_BLOCK_SIZE 16



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
}

std::map<std::string, std::string> makeHashes(std::vector<std::string> &words){
    std::map<std::string, std::string> final;
    char* tmp, md;
    const unsigned char *d;

    char pokus[]= "ahoj";
    unsigned char vyflusniSem[AES_BLOCK_SIZE];

    for (auto & word : words) {
        std::stringstream s;
        MD5((unsigned char*)word.c_str(), strlen(word.c_str()), (unsigned char *) &vyflusniSem);
        for (unsigned char j : vyflusniSem) {
            s << std::hex << std::setw(2) << std::setprecision(2) << (unsigned int)j;
        }
//        std::cout<<s.str()<<std::endl;
        final[word]=s.str();
        s.flush();
    }
    return final;



//    MD5((unsigned char*)pokus, strlen(pokus), (unsigned char *) &vyflusniSem);
//    for (unsigned char i : vyflusniSem) {
//        s << std::hex << std::setw(2) << std::setprecision(2) << (int)i;
//    }
//    std::cout << s.str();
//    s.flush();


//            std::cout << std::hex << std::setw(2) << std::setprecision(2) << tmp <<" ";
//        printf("%2.2x", result[i]);
//}
//        std::cout<< tmp<< std::endl;
//    std::cout<< s.str()<<std::endl;
//        final[words[i]]=s.str();
//s.flush();
//tmp="";

}


int main() {
    std::vector<std::string> words;
    generateWords(words, 3);
    makeHashes(words);
//    for (auto & word : words) {
//        std::cout << word << std::endl;
//    }
    return 0;
}
