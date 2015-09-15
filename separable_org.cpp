/*File: separable_org.cpp
 *Author: Michael Huelsman
 *Description:
 *  A class which represents the pivotal piece of NBGD as it is the
 *  basis of organism for the GA. This class provides a frame work for
 *  interacting with a neural network during the GA process
 *Date Started: 10 Sept 2015
 *Last Update: 10 Sept 2015
 *(C) All work is copyright of Michael Huelsman under the MIT Lisence
 */

#include "separable_org.hpp"

//Creation & construction
SeparableOrg::SeparableOrg(){
  byteString = 0;
  bytesPerChunk = 0;
  chunkCount = 0;
}

SeparableOrg::SeparableOrg(int chunkSize,int count){
  bytesPerChunk = chunkSize;
  chunkCount = count;
  byteString = new unsigned char[chunkSize*chunkCount];
}

SeparableOrg::~SeparableOrg(){
  if(byteString != 0)delete[] byteString;
  byteString = 0;
  bytesPerChunk = 0;
  chunkCount = 0;
}

SeparableOrg::SeparableOrg(const SeparableOrg &copy){
  bytesPerChunk = copy.bytesPerChunk;
  chunkCount = copy.chunkCount;
  byteString = new unsigned char[bytesPerChunk * chunkCount];
  for(int i = 0;i < bytesPerChunk*chunkCount;i++){
    byteString[i] = copy.byteString[i];
  }
}

SeparableOrg &SeparableOrg::operator=(const SeparableOrg &copy){
  if(byteString != 0)delete[] byteString;
  bytesPerChunk = copy.bytesPerChunk;
  chunkCount = copy.chunkCount;
  byteString = new unsigned char[bytesPerChunk * chunkCount];
  for(int i = 0;i < bytesPerChunk*chunkCount;i++){
    byteString[i] = copy.byteString[i];
  }
}

//info
int SeparableOrg::numChunks(){
  return chunkCount;
}

int SeparableOrg::chunkSize(){
  return bytesPerChunk;
}
//chunk retrieval
unsigned char *SeparableOrg::getChunk(int i){
  if(i >= chunkCount)return 0;
  return &byteString[i*bytesPerChunk];
}

unsigned char *SeparableOrg::operator[](int i){
  if(i >= chunkCount)return 0;
  return &byteString[i*bytesPerChunk];
}

//NN usage
bool SeparableOrg::schemaTransform(int from, int to, NeuralNet transform){
}

unsigned char SeparableOrg::randomByte(){
  int temp = rand();
  unsigned char *tempPtr = &temp;
  return tempPtr[1];
}
