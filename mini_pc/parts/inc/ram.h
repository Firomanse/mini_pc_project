#ifndef RAM_H
#define RAM_H

#include <iostream> //for tests

#include "../../base/inc/component.h"
#include "../../base/inc/cluster.h"
#include "../../base/inc/preset_loader.h"

class Ram : public Component
{
public:
  Ram(const int&);

  void readPreset(const std::string&);

private:
  PresetLoader* preset_loader;
  //array
};

#endif //RAM_H
