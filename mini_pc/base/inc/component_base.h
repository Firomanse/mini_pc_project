#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

#include "cluster_set.h"

#include <iostream>

class ComponentBase
{
public:
  ComponentBase(const unsigned&);

  void showDump();

protected:
  unsigned size;
  ClusterSet* array;
};

#endif //COMPONENT_BASE_H
