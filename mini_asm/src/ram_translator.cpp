#include "../inc/ram_translator.h"

RamTranslator::RamTranslator(const std::string& working_dir_)
{
  working_dir = working_dir_;
}

char RamTranslator::end()
{
  ++format_counter;
  if (format_counter % 16 == 0)
  {
    return '\n';
  }
  else
  {
    return ' ';
  }
}

void RamTranslator::work(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/output/" + working_file);
  output_stream.open(working_dir + "/../firmware/mem_dump/" + working_file);

  if (input_stream.is_open())
  {
    int bit;
    while (format_counter < 1024)
    {
      if (input_stream >> bit)
      {
        output_stream << bit << end();
      }
      else
      {
        output_stream << '0' << end();
      }
    }
  }
  else
  {
    std::cout << "file hasn't been opened" << std::endl;
  }
}
