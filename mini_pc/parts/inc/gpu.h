#ifndef GPU_H
#define GPU_H

#include "../../base/inc/component.h"
#include <iostream>

class Gpu;
#include "bus.h"

class Gpu : public Component
{
public:
  Gpu(const int&);
  void writeBuf(const ClusterSet&);
};

#endif //GPU_H
