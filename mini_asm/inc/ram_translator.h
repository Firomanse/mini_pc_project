#ifndef RAM_TRANSLATOR
#define RAM_TRANSLATOR

#include <iostream>
#include <fstream>

class RamTranslator
{
public:
  RamTranslator(const std::string&);

  char end();
  void work(const std::string&);

private:
  std::string working_dir;
  int format_counter = 0;
};

#endif // RAM_TRANSLATOR
