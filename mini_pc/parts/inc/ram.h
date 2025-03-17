#ifndef RAM_H
#define RAM_H

#include <fstream>
#include <iostream> //for tests

#include "../../base/inc/component.h"
#include "../../base/inc/cluster.h"

class Ram : public Component
{
public:
  Ram(const int&);

  void readPreset(const std::string&);

private:
  //array
};

#endif //RAM_H
