/*FILE: neural_net.hpp
 *Author: Michael Huelsman
 *Start Date: 21 Sept 2015
 *Notes:
 *
*/

#ifndef NEURAL_NET_HPP
#define NEURAL_NET_HPP

#include "neuron.hpp"

class NeuralNetwork{
public:
  // constructors among others
  NeuralNetwork();
  NeuralNetwork(int *layerSizes, int layers);
  NeuralNetwork(const NeuralNetwork &copy);
  ~NeuralNetwork();
  NeuralNetwork &operator=(const NeuralNetwork &copy);

  //run and train(gun)
  bool run(double *inputs, int inputSize, double *outputs, int outputSize);
  bool train(double *inputs, int inputSize, double *expected, int expectedSize);
protected:
  void clear(); //clears out all activation and inputs for a fresh run
private:
  Neuron **network;
  int networkSize; //# of layers
  int *layerSize; //size of each layer
};

#endif
