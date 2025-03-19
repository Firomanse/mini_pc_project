#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <fstream>

class Interpreter
{
public:
  Interpreter(const std::string&);

  void toAddresses(const std::string&);
  std::string changeCommands(const std::string&);
  void toBinary(const std::string&);
  void work(const std::string&);

private:
  std::string working_dir;
};

#endif //INTERPRETER_H
