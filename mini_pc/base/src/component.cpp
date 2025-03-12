#include "../inc/component.h"

Component::Component(const unsigned& size_)
            : ComponentBase(size_) //diamond inheritance problem
            , ReadOnlyComponent(size_)
            , WriteOnlyComponent(size_)
{  }

void Component::writeBuf(const ClusterSet&)
{  }

ClusterSet Component::readBuf() const
{
  ClusterSet* output = new ClusterSet(2);
  return (*output);
}
