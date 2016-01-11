/*File: separable_org.hpp
 *Author: Michael Huelsman
 *Description:
 *  A class which represents the pivotal piece of NBGD as it is the
 *  basis of organism for the GA. This class provides a frame work for
 *  interacting with a neural network during the GA process
 *Date Started: 10 Sept 2015
 *Last Update: 24 Oct 2015
 *(C) All work is copyright of Michael Huelsman under the MIT Licence
 */

#ifndef SEPARABLEORG_HPP
#define SEPARABLEORG_HPP

#include "neural_net.hpp"

struct TransformCoord{
  int from;
  int to;
};

class SeparableOrganism{
public:
  virtual SeparableOrganism() = 0;
  virtual SeparableOrganism(const SeparableOrganism &copy) = 0;
  virtual ~SeparableOrganism() = 0;
  virtual SeparableOrganism& operator=(const SeparableOrganism &copy) = 0;

  //required methods
  virtual mate(SeparableOrganism &other, SeparableOrganism *children) = 0;
  virtual void applyTransform(NeuralNetwork transform) = 0;
  virtual void mutate() = 0;
  virtual void setFitness(double to) = 0;
  virtual void addTransform(TransformCoord tc) = 0;
protected:
private:
};

#endif
