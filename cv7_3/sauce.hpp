//
// Created by kvitajin on 17.11.20.
//

#ifndef CV7_3_SAUCE_HPP
#define CV7_3_SAUCE_HPP

#define LETTERS_SIZE 88
#include <iostream>
#include <cmath>
#include "cuda.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "md5.hpp"


std::string LETTERS [LETTERS_SIZE]={"a", "á", "b", "c", "č", "d", "ď", "e", "é", "ě", "f", "g", "h", "i", "í", "j", "k",
                                    "l", "m", "n", "ň", "o", "ó", "p", "q", "r", "ř", "s", "š", "t", "ť", "u", "v", "w", "x",
                                    "y", "ý", "z", "ž",
                                    "A", "Á", "B", "C", "Č", "D", "Ď", "E", "É", "Ě", "F", "G", "H", "I", "I", "J", "K",
                                    "L", "M", "N", "Ň", "O", "Ó", "P", "Q", "R", "Ř", "S", "Š", "T", "Ť", "U", "V", "W", "X",
                                    "Y", "Ý", "Z", "Ž",
                                    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

__global__ void wordCompute (char* lett);



class Compute{
    int wordLen;
    unsigned long long numOfWords;

public:
    Compute(int wordLen);
    static unsigned long long calculateNumberOfWords(int numberOfLetters);
    void gpuHandler(unsigned long long len);

};




#endif //CV7_3_SAUCE_HPP
