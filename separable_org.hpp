/*File: separable_org.hpp
 *Author: Michael Huelsman
 *Description:
 *  A class which represents the pivotal piece of NBGD as it is the
 *  basis of organism for the GA. This class provides a frame work for
 *  interacting with a neural network during the GA process
 *Date Started: 10 Sept 2015
 *Last Update: 10 Sept 2015
 *(C) All work is copyright of Michael Huelsman under the MIT Lisence
 */

#include "neural_net.hpp"

class SeparableOrg{
public:
  //Creation & construction
  SeparableOrg();
  SeparableOrg(int chunkSize,int count);
  ~SeparableOrg();
  SeparableOrg(const SeparableOrg &copy);
  SeparableOrg &operator=(const SeparableOrg &copy);

  //info
  int numChunks();
  int chunkSize();
  //chunk retrieval
  unsigned char *getChunk(int i);
  unsigned char *operator[](int i);

  //NN usage
  bool schemaTransform(int from, int to, NeuralNet transform);
protected:
  unsigned char randomByte();
private:
  unsigned char *byteString;
  int bytesPerChunk;
  int chunkCount;
};
