#include "../inc/cluster.h"

Cluster::Cluster()
{
  array[0] = 0;
  array[1] = 0;
  array[2] = 0;
  array[3] = 0;
}

Cluster::Cluster(const bool& bit3, const bool& bit2, const bool& bit1, const bool& bit0)
{
  array[0] = bit0;
  array[1] = bit1;
  array[2] = bit2;
  array[3] = bit3;
}

Cluster::Cluster(const Cluster& cluster)
{
  for (int i = 0; i < size; ++i)
  {
    array[i] = cluster[i];
  }
}


Cluster& Cluster::operator=(const Cluster& cluster)
{
  for (int i = 0; i < size; ++i)
  {
    array[i] = cluster[i];
  }
  return *this;
}

bool& Cluster::operator[](const unsigned& index) const
{
  return array[index];
}

short Cluster::toDecimal()
{
  return array[3] * 8 + array[2] * 4 + array[1] * 2 + array[0];
}

Cluster& Cluster::inverse()
{
  for (int i = 0; i < size; ++i)
  {
    array[i] = !array[i];
  }
  return *this;
}

short Cluster::getSize()
{
  return size;
}
