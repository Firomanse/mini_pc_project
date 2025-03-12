#include "../inc/read_only_component.h"

ReadOnlyComponent::ReadOnlyComponent(const unsigned& size_) : ComponentBase(size_)
{  }

Cluster ReadOnlyComponent::read(const unsigned& index) const
{
  return (*array)[index];
}
