#ifndef CPU_H
#define CPU_H

#include "../../base/inc/component.h"
#include "../../base/inc/clock.h"

#include <iostream> //for output tests

class Cpu;
#include "bus.h"

class Cpu : public Component
{
public:
  Cpu(const int&);

  Bus* getBus();
 
  int combineAddress();
  void debug(const bool&, const std::string&);

  Cluster logicAnd(const Cluster&, const Cluster&);
  Cluster logicOr(const Cluster&, const Cluster&);
  Cluster logicAdd(const Cluster&, const Cluster&);
  Cluster logicSub(const Cluster&, const Cluster&);

  void getCommand();
  bool executeCommand(const bool&);

private:
  //ClusterSet* array
  //int size

  Bus* bus;
};

#endif //CPU_H
