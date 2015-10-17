#include "neural_net.hpp"

#define LEARNING_RATE 0.002

//public:
// constructors among others
NeuralNetwork::NeuralNetwork(){
  networkSize = 0;
  network = 0;
  layerSize = 0;
}

NeuralNetwork::NeuralNetwork(int *layerSizes, int layers){
  networkSize = layers;
  layerSize = new int[networkSize];
  network = new Neuron*[networkSize];
  for(int i = 0;i < networkSize;i++){
    layerSize[i] = layerSizes[i];
    network = new Neuron[layerSize[i]];
    for(int j = 0;j < layerSize[i];j++){
      if(i == (networkSize-1)){
        network[i][j] = Neuron(0);
      }
      else{
        network[i][j] = Neuron(layerSize[i+1]);
      }
    }
  }
}

NeuralNetwork::NeuralNetwork(const NeuralNetwork &copy){
  networkSize = copy.networkSize;
  layerSize = new int[networkSize];
  network = new Neuron*[networkSize];
  for(int i = 0;i < networkSize;i++){
    layerSize[i] = copy.layerSize[i];
    network[i] = new Neuron[layerSize[i]];
    for(int j = 0;j < layerSize[i];j++){
      if(i == (networkSize-1)){
	network[i][j] = Neuron(0);
      }
      else{
	network[i][j] = Neuron(layerSize[i+1]);
      }
    }
  }
}

NeuralNetwork::~NeuralNetwork(){
  if(network != 0){
    for(int i = 0;i < networkSize;i++){
      delete[] network[i];
    }
    delete[] network;
    network = 0;
  }
  if(layerSize != 0){
    delete[] layerSize;
    layerSize = 0;
  }
  networkSize = 0;
}

NeuralNetwork &NeuralNetwork::operator=(const NeuralNetwork &copy){
  //remove any leftovers or current value
   if(network != 0){
    for(int i = 0;i < networkSize;i++){
      delete[] network[i];
    }
    delete[] network;
    network = 0;
  }
  if(layerSize != 0){
    delete[] layerSize;
    layerSize = 0;
  }
  networkSize = 0;
  //add in the new contents
  networkSize = copy.networkSize;
  layerSize = new int[networkSize];
  network = new Neuron*[networkSize];
  for(int i = 0;i < networkSize;i++){
    layerSize[i] = copy.layerSize[i];
    network[i] = new Neuron[layerSize[i]];
    for(int j = 0;j < layerSize[i];j++){
      if(i == (networkSize-1)){
	network[i][j] = Neuron(0);
      }
      else{
	network[i][j] = Neuron(layerSize[i+1]);
      }
    }
  }
  //return the object
  return *this;
}

//run and train(gun)
bool NeuralNetwork::run(double *inputs, int inputSize, double *outputs, int outputSize){
  if(inputSize != layerSize[0] || outputSize != layerSize[networkSize-1])return false;
  for(int i = 0;i < layerSize[0];i++){
    network[0][i].addInput(inputs[i]);
  }
  for(int i = 1;i < networkSize;i++){
    double *currentOutput = new double[layerSize[i]];
    //gather outputs from the previous layer and add them up
    for(int j = 0;j < layerSize[i-1];j++){
      double *temp = new double[layerSize[i]];
      network[i-1][j].run(temp,layerSize[i]);
      for(int k = 0;k < layerSize[i];k++){
	if(j == 0)currentOutput[k] = 0;
	currentOutput[k] += temp[k];
      }
      delete[] temp;
    }
    //apply gathered output from the previous layer to the current layer
    for(int j = 0;j < layerSize[i];j++){
      network[i][j].addInput(currentOutput[j]);
    }
    delete[] currentOutput;
  }
  //modify the required values for returning to the caller
  int outLayer = networkSize-1;
  for(int i = 0;i < outputSize;i++){
    outputs[i] = network[outLayer][i].getOutput();
  }
  return true;
}

bool NeuralNetwork::train(double *inputs, int inputSize, double *expected, int expectedSize){
  if(inputSize != layerSize[0] || expectedSize != layerSize[networkSize-1])return false;
  double *output = new double[networkSize-1];
  if(run(inputs,inputSize, output, expectedSize)){
    for(int i = 0;i < expectedSize;i++){
      ouput[i] = expected[i] - output[i];
      network[networkSize-1][i].train(output[i],LEARNING_RATE);
    }
    //back propagation
    for(int i = networkSize-2;i >= 0;i--){
      delete[] output;
      output = new double[layerSize[i+1]];
      for(int j = 0;j < layerSize[i+1];j++){
	output[j] = network[i+1][j].getError();
      }
      for(int j = 0;j < layerSize[i];j++){
	network[i][j].train(output,LEARNING_RATE);
      }
    }
  }
  delete[] output;
}

//protected

void NeuralNetwork::clear(){
  for(int i = 0;i < networkSize;i++){
    for(int j = 0;j < layerSize[i];j++){
      network[i][j].clear();
    }
  }
}
