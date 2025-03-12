#include "../inc/cluster_set.h"

ClusterSet::ClusterSet(const int& size_)
{
  size = size_;
  array = new Cluster[size];
}

Cluster& ClusterSet::operator[](const unsigned& index) const
{
  return array[index];
}

int ClusterSet::getSize()
{
  return size;
}
