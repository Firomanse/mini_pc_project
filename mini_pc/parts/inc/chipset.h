#ifndef CHIPSET_H
#define CHIPSET_H

#include "../../base/inc/component.h"
#include <iostream>

class Chipset;

#include "bus.h"

class Chipset : public Component
{
public:
  Chipset(const int&);

  ClusterSet readBuf() const override;
};

#endif //CHIPSET_H
