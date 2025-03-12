#include "../inc/component_base.h"

ComponentBase::ComponentBase(const unsigned& size_)
{
  size = size_;
  array = new ClusterSet(size);
} // + virtual methods deleted and defined in child classes?

void ComponentBase::showDump()
{
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      std::cout << (*array)[i][3 - j] << ' ';
    }
    if (i % 4 == 3)
    {
      std::cout << std::endl;
    }
    else
    {
      std::cout << ' ';
    }
  }
}
