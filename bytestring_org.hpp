/*File: bytestring_org.hpp
 *Author: Michael Huelsman
 *Description:
 *  A dervied class of the SeparableOrganism this represents
 *  a determined number of bytes which ar used to represent
 *  genetic information
 *Date Started: 22 Oct 2015
 *Last Update: 24 Oct 2015
 *(C) All work is copyright of Michael Huelsman under the MIT Licence
 */


#ifndef BYTESTRINGORG_HPP
#define BYTESTRINGORG_HPP

#include <vector>
using std::vector;

class ByteStringOrganism: public SeparableOrganism{
public:
  //constructors
  ByteStringOrganism();
  ByteStringOrganism();
  ByteStringOrganism(const ByteStringOrganism &copy);
  ~ByteStringOrganism();
  ByteStringOrganism& operator=(const ByteStringOrganism &copy);

  //required methods
  void mate(ByteStringOrganism &other);
  void applyTransform(NeuralNetwork transform);
  void mutate();
  void setFitness(double to);
  void addTransform(TransformCoord tc);
protected:
private:
  unsigned char *data;
  int size;
  vector<TransformCoord> transforms;
  double fitness;
};

#endif