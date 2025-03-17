#include "../inc/ram.h"

Ram::Ram(const int& size_) : Component(size_), ComponentBase(size_) //diamond inheritance problem
{  }

void Ram::readPreset(const std::string& working_dir)
{
  std::ifstream stream;
  stream.open(working_dir + "/mini_pc/parts/firmware/rom_preset");
  if (stream.is_open())
  {
    bool tmp;
    for (int i = 0; i < 256; ++i)
    {
      for (int j = 0; j < 4; ++j)
      {
        stream >> tmp;
        (*array)[i][3 - j] = tmp;
      }
    }
  }
  else
  {
    std::cout << "preset hasn't been opened" << std::endl;
  }
}
