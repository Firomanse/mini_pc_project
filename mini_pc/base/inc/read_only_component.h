#ifndef READ_ONLY_COMPONENT_H
#define READ_ONLY_COMPONENT_H

#include "component_base.h"

class ReadOnlyComponent : virtual public ComponentBase
{
public:
  ReadOnlyComponent(const unsigned&);

  Cluster read(const unsigned&) const;
};

#endif //READ_ONLY_COMPONENT_H
