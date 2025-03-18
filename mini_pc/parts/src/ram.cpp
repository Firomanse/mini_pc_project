#include "../inc/ram.h"

Ram::Ram(const int& size_, const std::string& working_dir_)
    : Component(size_), ComponentBase(size_) //diamond inheritance problem
{
  working_dir = working_dir_;
}

void Ram::readPreset(const std::string& working_file)
{
  preset_loader = new PresetLoader(working_dir);

  ClusterSet* preset_array = preset_loader->load(working_file);

  for (int i = 0; i < 256; ++i)
  {
    (*array)[i] = (*preset_array)[i];
  }
}
