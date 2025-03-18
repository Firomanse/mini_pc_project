#include "../inc/ram.h"

Ram::Ram(const int& size_) : Component(size_), ComponentBase(size_) //diamond inheritance problem
{  }

void Ram::readPreset(const std::string& working_dir)
{
  preset_loader = new PresetLoader(working_dir);

  ClusterSet* preset_array = preset_loader->load("new_program");

  for (int i = 0; i < 256; ++i)
  {
    (*array)[i] = (*preset_array)[i];
  }
}
