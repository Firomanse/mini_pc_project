#ifndef RAM_H
#define RAM_H

#include <iostream> //for tests

#include "../../base/inc/component.h"
#include "../../base/inc/cluster.h"
#include "../../base/inc/preset_loader.h"

class Ram : public Component
{
public:
  Ram(const int&, const std::string&);

  void readPreset(const std::string&);

private:
  PresetLoader* preset_loader;
  std::string working_dir;
  //array
};

#endif //RAM_H
