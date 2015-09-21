/*File: neuron.cpp
 *Author: Michael Huelsman
 *Copyright (c) Michael Huelsman 2015
 *Start Date: 21 Sept 2015
 *Notes:
 *
 */
#include "neuron.hpp"
#include <cmath>
//public
//constructors among others
Neuron::Neuron(){
  weights = 0;
  weightSize = 0;
  input = 0.0;
  error = 0.0;
  bias = 0.0;
}

Neuron::Neuron(int size){
  weightSize = size;
  weights = new double[weightSize];
  for(int i = 0;i < weightSize;i++){
    weights[i] = randomStrength();
  }
  bias = randomStrength();
  error = 0.0;
  input = 0.0;
}

Neuron::Neuron(const Neuron &copy){
  weightSize = copy.weightSize;
  weights = new double[weightSize];
  for(int i = 0;i < weightSize;i++){
    weights[i] = copy.weights[i];
  }
  bias = copy.bias;
  error = copy.error;
  input = copy.input;
}

Neuron::~Neuron(){
  if(weights != 0)delete[] weights;
  weights = 0.0;
  weightSize = 0.0;
  bias = 0.0;
  error = 0.0;
  input = 0.0;
}

Neuron &Neuron::operator=(const Neuron & copy){
  if(weights != 0)delete[] weights;
  weightSize = copy.weightSize;
  weights = new double[weightSize];
  for(int i = 0;i < weightSize;i++){
    weights[i] = copy.weights[i];
  }
  bias = copy.bias;
  error = copy.error;
  input = copy.input;
  return *this;
}

//basic manipulation/accessors
void Neuron::addInput(int add){
  input += add;
}

double Neuron::getError(){
  return error;
}

void Neuron::clear(){ //removes input, error, etc.
  input = 0.0;
  error = 0.0;
}

//basic operation
bool Neuron::train(double expected, double lr){
  error = expected - activation();
  error = error*gradient();
  bias += lr*error;
  return true;
}

bool Neuron::train(double *errors, int size, double lr){
  if(size != weightSize)return false;
  for(int i = 0;i < weightSize;i++){
    error += weights[i]*errors[i];
  }
  error = gradient() * error;
  bias += lr*error;
  double temp = activation();
  for(int i = 0;i < weightSize;i++){
    weights[i] += lr*temp*errors[i];
  }
  return true;
}

bool Neuron::run(double *output, int size){
  if(size != weightSize)return false;
  double temp = activation();
  for(int i = 0;i < weightSize;i++){
    output[i] = temp*weights[i];
  }
  return true;
}

//protected
double Neuron::activation(){
  return tanh(input+bias);
}

double Neuron::gradient(){
  return (1-(activation()*activation()));
}

double Neuron::randomStrength(){
  return ((double)(rand()%100000))/100000.0;
}
