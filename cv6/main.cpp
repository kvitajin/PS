#include <cmath>
#include <string>
#include <cstring>

using namespace std;
typedef union uwb {
    unsigned w;
    unsigned char b[4];
} MD5union;

typedef unsigned DigestArray[4];

static unsigned func0(unsigned abcd[]){
    return (abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);
}

static unsigned func1(unsigned abcd[]){
    return (abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);
}

static unsigned func2(unsigned abcd[]){
    return  abcd[1] ^ abcd[2] ^ abcd[3];
}

static unsigned func3(unsigned abcd[]){
    return abcd[2] ^ (abcd[1] | ~abcd[3]);
}

typedef unsigned(*DgstFctn)(unsigned a[]);

static unsigned *calctable(unsigned *k)
{
    double s, pwr;
    int i;

    pwr = pow(2.0, 32);
    for (i = 0; i<64; i++) {
        s = fabs(sin(1.0 + i));
        k[i] = (unsigned)(s * pwr);
    }
    return k;
}

static unsigned rol(unsigned r, short N)
{
    unsigned  mask1 = (1 << N) - 1;
    return ((r >> (32 - N)) & mask1) | ((r << N) & ~mask1);
}

static unsigned* MD5Hash(string msg)
{
    int mlen = msg.length();
    static DigestArray h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    static DgstFctn ff[] = { &func0, &func1, &func2, &func3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rot0[] = { 7, 12, 17, 22 };
    static short rot1[] = { 5, 9, 14, 20 };
    static short rot2[] = { 4, 11, 16, 23 };
    static short rot3[] = { 6, 10, 15, 21 };
    static short *rots[] = { rot0, rot1, rot2, rot3 };
    static unsigned kspace[64];
    static unsigned *k;

    static DigestArray h;
    DigestArray abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;
    short *rotn;
    union {
        unsigned w[16];
        char     b[64];
    }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;

    if (k == NULL) k = calctable(kspace);

    for (q = 0; q<4; q++) h[q] = h0[q];

    {
        grps = 1 + (mlen + 8) / 64;
        msg2 = (unsigned char*)malloc(64 * grps);
        memcpy(msg2, msg.c_str(), mlen);
        msg2[mlen] = (unsigned char)0x80;
        q = mlen + 1;
        while (q < 64 * grps){ msg2[q] = 0; q++; }
        {
            MD5union u;
            u.w = 8 * mlen;
            q -= 8;
            memcpy(msg2 + q, &u.w, 4);
        }
    }

    for (grp = 0; grp<grps; grp++)
    {
        memcpy(mm.b, msg2 + os, 64);
        for (q = 0; q<4; q++) abcd[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotn = rots[p];
            m = M[p]; o = O[p];
            for (q = 0; q<16; q++) {
                g = (m*q + o) % 16;
                f = abcd[1] + rol(abcd[0] + fctn(abcd) + k[q + 16 * p] + mm.w[g], rotn[q % 4]);

                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p = 0; p<4; p++)
            h[p] += abcd[p];
        os += 64;
    }

    return h;
}

static string GetMD5String(string msg) {
    string str;
    int j, k;
    unsigned *d = MD5Hash(msg);
    MD5union u;
    for (j = 0; j<4; j++){
        u.w = d[j];
        char s[9];
        sprintf(s, "%02x%02x%02x%02x", u.b[0], u.b[1], u.b[2], u.b[3]);
        str += s;
    }

    return str;
}
#define LETTERS_SIZE 90


std::string LETTERS [LETTERS_SIZE]={"a", "á", "b", "c", "č", "d", "ď", "e", "é", "ě", "f", "g", "h", "ch", "i", "í", "j", "k",
                                    "l", "m", "n", "ň", "o", "ó", "p", "q", "r", "ř", "s", "š", "t", "ť", "u", "v", "w", "x",
                                    "y", "ý", "z", "ž",
                                    "A", "Á", "B", "C", "Č", "D", "Ď", "E", "É", "Ě", "F", "G", "H", "Ch", "I", "I", "J", "K",
                                    "L", "M", "N", "Ň", "O", "Ó", "P", "Q", "R", "Ř", "S", "Š", "T", "Ť", "U", "V", "W", "X",
                                    "Y", "Ý", "Z", "Ž",
                                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};


#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <zconf.h>
#include <wait.h>
#include <fstream>
#include <vector>
#include <thread>


/**
 * funkce generuje jeden string podle zadane pozice a delky pozadovaneho slova
 * @param wordPosition  od ktere pozice ma program generovat (pro delku 2plati: 0=aa, 1=áa, 2= ba,...)
 * @param wordLen       kolik znaku ma jedno slovo
 * @param makeHash      jestli ma dane slova hashovat
 * @param print         jestli ma dany vysledek (slovo nebo hash) vypsat
 */
void generateString(int wordPosition, int wordLen, bool makeHash, bool print){
    int tmp, tmpWord=wordPosition;
    std::string word;
    for (int i = 0; i < wordLen; ++i) {                         ///princip podobny prevodu mezi hex a dec soustavou
        tmp= tmpWord % LETTERS_SIZE;
        word+=LETTERS[tmp];
        tmpWord/= LETTERS_SIZE;
    }

    if (makeHash && print){
        std::cout <<  GetMD5String(word) << std::endl;
    }
    else if (print){
        std::cout << word << std::endl;
    }
    else if (makeHash){
        auto hash = GetMD5String(word);
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

void threadHeader(int wordLen, int numberOfForks, bool makeHash, bool print){
    int numberOfWords = calculateNumberOfWords(wordLen);
    int partSize = floor(numberOfWords/numberOfForks);
    std::vector<std::thread> threads;
    for (int i = 0; i < numberOfForks; ++i) {
        if (i+1==numberOfForks){
            int lastPart = numberOfWords-i*partSize;
            threads.push_back(std::thread(forkController,wordLen, partSize*i, lastPart, makeHash, print));
        }
        threads.push_back(std::thread(forkController,wordLen, partSize*i, partSize, makeHash, print));
    }
    for (std::thread & th : threads){
        if (th.joinable())
            th.join();
    }
}


void makeCSV(int wordLen, int numberOfForks, bool makeHash, bool print){
    std::chrono::steady_clock sc;
    for (int wLen = 1; wLen < wordLen+1; ++wLen) {
        std::string fileName;
        fileName.push_back((char)wLen + 48);
        fileName.append("znaky.csv");
        std::ofstream output;
        output.open(fileName);
        output<<"FORKS\tTIME\n";
        for (int j = 1; j < 100; ++j) {
            auto start=sc.now();
            threadHeader(wLen, numberOfForks, makeHash, print);
            auto end=sc.now();
            auto time_span = static_cast<std::chrono::duration<double>>(end - start);
            output<<j <<"\t"<<time_span.count()<<std::endl;
        }
        output.close();
    }
}

using namespace std;

int main() {
    bool print = false;
    bool makeHash = true;
    int wordLen=4;
    int numberOfForks= 100;
    makeCSV( wordLen, numberOfForks, makeHash, print);
//    std::cout<<calculateNumberOfWords(8);
}


