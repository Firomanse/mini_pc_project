#include "../inc/gpu.h"

Gpu::Gpu(const int& size_) : Component(size_), ComponentBase(size_) //diamond inheritance problem
{  }

void Gpu::writeBuf(const ClusterSet& data)
{
  int tmp;
  tmp = data[1].toDecimal() * 16 + data[0].toDecimal();
  //convert int to char
  std::cout << tmp << std::endl;
}
