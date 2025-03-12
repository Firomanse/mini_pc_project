#ifndef COMPONENT_H
#define COMPONENT_H

#include "read_only_component.h"
#include "write_only_component.h"

class Component : public ReadOnlyComponent
                , public WriteOnlyComponent
{
public:
  Component(const unsigned&);

  virtual void writeBuf(const ClusterSet&);
  virtual ClusterSet readBuf() const;
};

#endif //COMPONENT_H
