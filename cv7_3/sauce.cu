#include "sauce.hpp"


Compute::Compute(int wordLen) {
    this->wordLen= wordLen;
    this->numOfWords= calculateNumberOfWords(wordLen);
}

unsigned long long Compute::calculateNumberOfWords(int numberOfLetters) {
    return (unsigned long long)pow(LETTERS_SIZE, numberOfLetters);

}

void Compute::gpuHandler(unsigned long long int numOfWOrd) {
    char *host_word, host_letter, *cuda_word, *cuda_letter;
    host_letter= &LETTERS[0];
//    strcpy(LETTERS)


//    cudaError_t cerr;
//    int threads = 256;
//    int blocks = ( this->wordLen + threads - 1 ) / threads;
//
//    // Memory allocation in GPU device
//    char *lett;
//    cerr = cudaMalloc( &lett, LETTERS->size()*sizeof(char) );
//    if ( cerr != cudaSuccess )
//        printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );
//
//    // Copy data from PC to GPU device
//    cerr = cudaMemcpy( lett, LETTERS, LETTERS->size()* sizeof( char ), cudaMemcpyHostToDevice );
//    if ( cerr != cudaSuccess )
//        printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );
//
//    // Grid creation
//    wordCompute<<< blocks, threads >>>( lett );
//
//    if ( ( cerr = cudaGetLastError() ) != cudaSuccess )
//        printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );
//
//    // Copy data from GPU device to PC
//    cerr = cudaMemcpy( P, cudaP, this->wordLen * sizeof( float ), cudaMemcpyDeviceToHost );
//    if ( cerr != cudaSuccess )
//        printf( "CUDA Error [%d] - '%s'\n", __LINE__, cudaGetErrorString( cerr ) );
//
//    // Free memory
//    cudaFree( cudaP );
}

__global__ void wordCompute( char* lett, const int gridIdx, const int gridDim) {
    dim3 cudaBlockSize(256);


}
