#include <iostream>
#include <vector>
#include <cmath>
#include <openssl/md5.h>
#include <cstring>
#include <iomanip>
#include <zconf.h>
#include <wait.h>

#define LETTERS_SIZE 90
#define AES_BLOCK_SIZE 16



std::string letters [LETTERS_SIZE]={"a", "á", "b", "c", "č", "d", "ď", "e", "é", "ě", "f", "g", "h", "ch", "i", "í", "j", "k",
                          "l", "m", "n", "ň", "o", "ó", "p", "q", "r", "ř", "s", "š", "t", "ť", "u", "v", "w", "x",
                          "y", "ý", "z", "ž",
                          "A", "Á", "B", "C", "Č", "D", "Ď", "E", "É", "Ě", "F", "G", "H", "Ch", "I", "I", "J", "K",
                          "L", "M", "N", "Ň", "O", "Ó", "P", "Q", "R", "Ř", "S", "Š", "T", "Ť", "U", "V", "W", "X",
                          "Y", "Ý", "Z", "Ž",
                          "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};



void makeMD5(std::string &word){

    unsigned char hashedWord[AES_BLOCK_SIZE];

    std::stringstream s;
    MD5((unsigned char *) word.c_str(), strlen(word.c_str()), (unsigned char *) &hashedWord);
    for (unsigned char j : hashedWord) {
        s << std::hex << std::setw(2) << std::setprecision(2) << (unsigned int) j;
    }
    std::cout<< s.str()<<std::endl;
}

void generateString(int wordPosition, int wordLen){
    int tmp;
    std::string word;
    for (int i = 0; i < wordLen; ++i) {                         ///princip podobny prevodu mezi hex a dec soustavou
        tmp= wordPosition % LETTERS_SIZE;
        word+=letters[tmp];
        wordPosition/= LETTERS_SIZE;
    }
    std::cout<<word<<std::endl;
//    makeMD5(word);
}
/**
 *
 * @param numberOfLetters
 * @return
 */
int calculateNumberOfWords(int numberOfLetters){
    return (int)pow(LETTERS_SIZE, numberOfLetters);
}

void forkController(int wordLen, int firstWord, int numOfWord){
    for (int i = 0; i < numOfWord; ++i) {
        generateString(firstWord+i, wordLen);
    }
}
void forkHeader(int wordLen, int numberOfForks){
    int status;
    int numberOfWords = calculateNumberOfWords(wordLen);
    int partSize = floor(numberOfWords/numberOfForks);
    for (int i = 0; i < numberOfForks; ++i) {
        int a = fork();
        if (a==0){
            if (i+1==numberOfForks){
                int lastPart = numberOfWords-i*partSize;
                forkController(wordLen, partSize*i, lastPart);

            }
            forkController(wordLen, partSize*i, partSize);
            exit(0);
        }
        else{
            waitpid(a, &status, 0);
        }

    }
}

int main() {
    int wordLen=3;
//    int num=calculateNumberOfWords(wordLen);
    forkHeader( wordLen, 10);
//    forkController(wordLen, 0, num);
//    for (int i = 0; i < num; ++i) {
//        generateString(i, wordLen);
//    }

    return 0;
}
