#include "../inc/write_only_component.h"

WriteOnlyComponent::WriteOnlyComponent(const unsigned& size_)
                     : ComponentBase(size_)
{  }

void WriteOnlyComponent::write(const unsigned& index, const Cluster& data)
{
  (*array)[index] = data;
}
