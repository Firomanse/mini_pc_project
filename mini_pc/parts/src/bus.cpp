#include "../inc/bus.h"

Bus::Bus(Cpu* cpu_instance)
{
  link(cpu_instance, 'c');
}

void Bus::link(Component* component_instance, const char& component_type)
{
  linked_devices.push_back(component_instance);
  linked_devices_types.push_back(component_type);
}

void Bus::writeToMemory(const int& memory_address, const Cluster& data)
{
  for (int i = 0; i < linked_devices.size(); ++i)
  {
    if (linked_devices_types.at(i) == 'm')
    {
      linked_devices.at(i)->write(memory_address, data);
    }
  }
}

Cluster Bus::readFromMemory(const int& memory_address)
{
  for (int i = 0; i < linked_devices.size(); ++i)
  {
    if (linked_devices_types.at(i) == 'm')
    {
      return linked_devices.at(i)->read(memory_address);
    }
  }
  return {0,0,0,0};
}

ClusterSet Bus::readFromKeyboard()
{
  ClusterSet* buffer = new ClusterSet(2);
  for (int i = 0; i < linked_devices.size(); ++i)
  {
    if (linked_devices_types.at(i) == 'i')
    {
      (*buffer) = linked_devices.at(i)->readBuf();
    }
  }
  return (*buffer);
}

void Bus::writeToGpu(const ClusterSet& buffer)
{
  for (int i = 0; i < linked_devices.size(); ++i)
  {
    if (linked_devices_types.at(i) == 'g')
    {
      linked_devices.at(i)->writeBuf(buffer);
    }
  }
}
