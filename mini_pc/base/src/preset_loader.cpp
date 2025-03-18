#include "../inc/preset_loader.h"

PresetLoader::PresetLoader(const std::string& working_dir_)
{
  working_dir = working_dir_;
}

ClusterSet* PresetLoader::load(const std::string& working_file)
{
  ClusterSet* array = new ClusterSet(256);

  std::ifstream input_stream;

  input_stream.open(working_dir + "/firmware/mem_dump/" + working_file);

  if (input_stream.is_open())
  {
    bool bit0, bit1, bit2, bit3;
    int i = 0;
    while (input_stream >> bit0)
    {
      input_stream >> bit1;
      input_stream >> bit2;
      input_stream >> bit3;

      (*array)[i / 4][i % 4] = bit3;
      ++i;
      (*array)[i / 4][i % 4] = bit2;
      ++i;
      (*array)[i / 4][i % 4] = bit1;
      ++i;
      (*array)[i / 4][i % 4] = bit0;
      ++i;
    }
  }
  else
  {
    std::cout << "preset hasn't been opened" << std::endl;
  }
  return array;
}
