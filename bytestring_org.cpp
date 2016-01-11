/*File: bytestring_org.cpp
 *Author: Michael Huelsman
 *Description:
 *  an implementation of bytestring_org.hpp
 *Date Started: 24 Oct 2015
 *Last Update: 24 Oct 2015
 *(C) All work is copyright of Michael Huelsman under the MIT Licence
 */


#include "bytestring_org.hpp"

//constructors
ByteStringOrganism(){
  data = 0;
  size = 0;
  transforms = vector<TransformCoord>();
  fitness = 0.0;
}

ByteStringOrganism(const ByteStringOrganism &copy){
  size = copy.size;
  fitness = copy.fitness
  data = new unsigned char[size];
  for(int i = 0;i < size;i++){
    data[i] = copy.data[i];
  }
  transforms = copy.transforms;
}

~ByteStringOrganism(){
  transforms = vector<TransformCoord>();
  fitness = 0.0;
  delete[] data;
  size = 0;
  data = 0;
}

ByteStringOrganism& operator=(const ByteStringOrganism &copy){
  fitness = 0.0;
  if(data != 0){
    delete[] data;
    size = 0;
    data = 0;
  }
  size = copy.size;
  fitness = copy.fitness
  data = new unsigned char[size];
  for(int i = 0;i < size;i++){
    data[i] = copy.data[i];
  }
  transforms = copy.transforms;
}

//required methods
void mate(ByteStringOrganism &other){
}

void applyTransform(NeuralNetwork transform){
}

void mutate(){
}

void setFitness(double to){
}

void addTransform(TransformCoord tc){
}