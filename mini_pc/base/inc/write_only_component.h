#ifndef WRITE_ONLY_COMPONENT_H
#define WRITE_ONLY_COMPONENT_H

#include "component_base.h"

class WriteOnlyComponent : virtual public ComponentBase
{
public:
  WriteOnlyComponent(const unsigned&);

  void write(const unsigned&, const Cluster&);
};

#endif //WRITE_ONLY_COMPONENT_H
