#ifndef BUS_H
#define BUS_H

#include <vector> // TODO: change std::vector to custom
#include "../../base/inc/clock.h"

class Bus;
#include "cpu.h"
#include "ram.h"
#include "gpu.h"
#include "chipset.h"

class Bus
{
public:
  Bus(Cpu*);

  void link(Component*, const char&);

  Cluster readFromMemory(const int&);
  void writeToMemory(const int&, const Cluster&);

  ClusterSet readFromKeyboard();

  void writeToGpu(const ClusterSet&);

private:
  std::vector<Component*> linked_devices;
  std::vector<char> linked_devices_types;
};

#endif //BUS_H
