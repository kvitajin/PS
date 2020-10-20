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



std::string LETTERS [LETTERS_SIZE]={"a", "á", "b", "c", "č", "d", "ď", "e", "é", "ě", "f", "g", "h", "ch", "i", "í", "j", "k",
                                    "l", "m", "n", "ň", "o", "ó", "p", "q", "r", "ř", "s", "š", "t", "ť", "u", "v", "w", "x",
                                    "y", "ý", "z", "ž",
                                    "A", "Á", "B", "C", "Č", "D", "Ď", "E", "É", "Ě", "F", "G", "H", "Ch", "I", "I", "J", "K",
                                    "L", "M", "N", "Ň", "O", "Ó", "P", "Q", "R", "Ř", "S", "Š", "T", "Ť", "U", "V", "W", "X",
                                    "Y", "Ý", "Z", "Ž",
                                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

/**
 * funkce generujici MD5
 * @param word  dane slovo, ktere je potreba zahashovat
 * @return      string s hashem
 */
std::string makeMD5(std::string &word){

    unsigned char hashedWord[AES_BLOCK_SIZE];

    std::stringstream s;
    MD5((unsigned char *) word.c_str(), strlen(word.c_str()), (unsigned char *) &hashedWord);
    for (unsigned char j : hashedWord) {
        s << std::hex << std::setw(2) << std::setprecision(2) << (unsigned int) j;
    }
    return s.str();
}

/**
 * funkce generuje jeden string podle zadane pozice a delky pozadovaneho slova
 * @param wordPosition  od ktere pozice ma program generovat (pro delku 2plati: 0=aa, 1=áa, 2= ba,...)
 * @param wordLen       kolik znaku ma jedno slovo
 * @param makeHash      jestli ma dane slova hashovat
 * @param print         jestli ma dany vysledek (slovo nebo hash) vypsat
 */

void generateString(int wordPosition, int wordLen, bool makeHash, bool print){
    int tmp;
    std::string word;
    for (int i = 0; i < wordLen; ++i) {                         ///princip podobny prevodu mezi hex a dec soustavou
        tmp= wordPosition % LETTERS_SIZE;
        word+=LETTERS[tmp];
        wordPosition/= LETTERS_SIZE;
    }

    if (makeHash && print){
        std::cout << makeMD5(word) << std::endl;
    }
    else if (print){
        std::cout << word << std::endl;
    }
    else if (makeHash){
        makeMD5(word);
    }

}
/**
 * pocita celkovy pocet slov, pomocna funkce
 * @param numberOfLetters
 * @return
 */
int calculateNumberOfWords(int numberOfLetters){
    return (int)pow(LETTERS_SIZE, numberOfLetters);
}
/**
 *  ridi jedno dane vlakno
 * @param wordLen   kolik znaku ma jedno slovo
 * @param firstWord od ktere pozice ma zacit vypisovat
 * @param numOfWord kolik jich ma dane vlakno vypsat
 * @param makeHash  jestli ma dane slova hashovat
 * @param print     jestli ma dany vysledek (slovo nebo hash) vypsat
 */
void forkController(int wordLen, int firstWord, int numOfWord, bool makeHash, bool print){
    for (int i = 0; i < numOfWord; ++i) {
        generateString(firstWord+i, wordLen, makeHash, print);
    }
}

/**
 * funkce ridici cely program
 * @param wordLen       kolik znaku ma jedno slovo
 * @param numberOfForks na kolik forku se ma dany program rozpadnout
 * @param makeHash      jestli ma dane slova hashovat
 * @param print         jestli ma dany vysledek (slovo nebo hash) vypsat
 */
void forkHeader(int wordLen, int numberOfForks, bool makeHash, bool print){
    int status;
    int numberOfWords = calculateNumberOfWords(wordLen);
    int partSize = floor(numberOfWords/numberOfForks);
    for (int i = 0; i < numberOfForks; ++i) {
        int a = fork();
        if (a==0){
            if (i+1==numberOfForks){
                int lastPart = numberOfWords-i*partSize;
                forkController(wordLen, partSize*i, lastPart, makeHash, print);
            }
            forkController(wordLen, partSize*i, partSize, makeHash, print);
            exit(0);
        }
        else{
            waitpid(a, &status, 0);
        }
    }
}

int main() {
    int wordLen=3;
    bool print = false;
    bool makeHash = true;

    forkHeader( wordLen, 10, makeHash, print);

    return 0;
}
