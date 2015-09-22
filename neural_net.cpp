#include "neural_net.hpp"

//public:
// constructors among others
NeuralNetwork(){
}

NeuralNetwork(int *layerSizes, int layers){
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

NeuralNetwork(const NeuralNetwork &copy){
}

~NeuralNetwork(){
}

NeuralNetwork &operator=(const NeuralNetwork &copy){
}

//run and train(gun)
bool run(double *inputs, int inputSize, double *outputs, int outputSize){
}

bool train(double *inputs, int inputSize, double *expected, int expectedSize){
}
