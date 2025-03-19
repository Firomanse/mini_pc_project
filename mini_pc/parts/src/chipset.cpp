#include "../inc/chipset.h"

Chipset::Chipset(const int& size_) : Component(size_), ComponentBase(size_) //diamond inheritance problem
{  }

ClusterSet Chipset::readBuf() const
{
  int tmp;
  std::cin >> tmp;
  // TODO: convert char to int

  ClusterSet* output = new ClusterSet(2);
  if (tmp >= 0 && tmp <= 16)
  {
    (*output)[0][3] = tmp / 8;
    tmp -= (tmp / 8) * 8;
    (*output)[0][2] = tmp / 4;
    tmp -= (tmp / 4) * 4;
    (*output)[0][1] = tmp / 2;
    tmp -= (tmp / 2) * 2;
    (*output)[0][0] = tmp;
  }
  return (*output);
}
