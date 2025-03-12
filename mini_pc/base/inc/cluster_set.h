#ifndef CLUSTER_SET_H
#define CLUSTER_SET_H

#include "cluster.h"

class ClusterSet
{
public:
  ClusterSet(const int&);

  Cluster& operator[](const unsigned&) const;

  int getSize();

private:
  int size;
  Cluster* array;
};

#endif //CLUSTER_SET_H
