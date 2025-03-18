#ifndef PRESET_LOADER
#define PRESET_LOADER

#include "cluster_set.h"

#include <iostream>
#include <fstream>

class PresetLoader
{
public:
  PresetLoader(const std::string&);

  ClusterSet* load(const std::string&);

private:
  std::string working_dir;
};

#endif //PRESET_LOADER
