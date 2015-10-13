/*File: neuron.hpp
 *Author: Michael Huelsman
 *Copyright (c) Michael Huelsman 2015
 *Start Date: 21 Sept 2015
 *Notes:
 *
 */

#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron{
public:
  //constructors among others
  Neuron();
  Neuron(int size);
  Neuron(const Neuron &copy);
  ~Neuron();
  Neuron &operator=(const Neuron & copy);

  //basic manipulation/accessors
  void addInput(int add);
  void addInputs(double *add, int size);
  void clear(); //removes input, error, etc.
  double getError();
  double getOutput();

  //basic operation
  bool train(double expected, double lr);
  bool train(double *errors, int size, double lr);
  bool run(double *output, int size);
protected:
  double activation();
  double gradient();
  double randomStrength();
private:
  double *weights;//connection strengths
  int weightSize;
  double bias;//bias weight
  double input;
  double error;
};

#endif
