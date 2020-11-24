#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <zconf.h>
#include <wait.h>
#include <fstream>
#include <vector>
#include <thread>
#include "md5.hpp"

#define LETTERS_SIZE 90


std::string LETTERS [LETTERS_SIZE]={"a", "á", "b", "c", "č", "d", "ď", "e", "é", "ě", "f", "g", "h", "ch", "i", "í", "j", "k",
                                    "l", "m", "n", "ň", "o", "ó", "p", "q", "r", "ř", "s", "š", "t", "ť", "u", "v", "w", "x",
                                    "y", "ý", "z", "ž",
                                    "A", "Á", "B", "C", "Č", "D", "Ď", "E", "É", "Ě", "F", "G", "H", "Ch", "I", "I", "J", "K",
                                    "L", "M", "N", "Ň", "O", "Ó", "P", "Q", "R", "Ř", "S", "Š", "T", "Ť", "U", "V", "W", "X",
                                    "Y", "Ý", "Z", "Ž",
                                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};


void forkController(int wordLen, int firstWord, int numOfWord, bool makeHash, bool print){
//    for (int i = 0; i < numOfWord; ++i) {
//        generateString(firstWord+i, wordLen, makeHash, print);
//    }
}

int calculateNumberOfWords(int numberOfLetters){
    return (int)pow(LETTERS_SIZE, numberOfLetters);
}

void gridHeader(int wordLen, int numberOfForks, bool makeHash, bool print){             //TODO edit it
    std::vector<std::thread> threads;
    int numberOfWords = calculateNumberOfWords(wordLen);
    int partSize = floor(numberOfWords/numberOfForks);
    for (int i = 0; i < numberOfForks; ++i) {
        if (i+1==numberOfForks){
            int lastPart = numberOfWords-i*partSize;
            threads.emplace_back(std::thread(forkController,wordLen, partSize*i, lastPart, makeHash, print));
        }
        threads.emplace_back(std::thread(forkController,wordLen, partSize*i, partSize, makeHash, print));
    }

    for (std::thread & th : threads){
        if (th.joinable())
            th.join();
    }

}

void makeCSV(int wordLen, int numberOfForks, bool makeHash, bool print){
    std::chrono::steady_clock sc;
    std::string fileName;
    fileName.push_back((char)wordLen + 48);
    fileName.append("znaky.csv");
    std::ofstream output;
    output.open(fileName);
    output<<"THREADS\tTIME\n";
    for (int j = 1; j < numberOfForks+1; ++j) {
        auto start=sc.now();
        gridHeader(wordLen, j, makeHash, print);
        auto end=sc.now();
        auto time_span = static_cast<std::chrono::duration<double>>(end - start);
        output<<j <<"\t"<<time_span.count()<<std::endl;
    }
    output.close();

}

int main() {
    bool print = false;
    bool makeHash = true;
    int wordLen=4;
    int numberOfForks= 100;
//    makeCSV( wordLen, numberOfForks, makeHash, print);
    std::cout<<md5("aa");
    return 0;
}
