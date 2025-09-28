#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <vector>
#include <fstream>

struct DictionaryItem
{
  std::string label;
  int address;
  int size;
};

class Interpreter
{
public:
  Interpreter(const std::string&);

  bool isStandardCommand(const std::string&);
  std::string tryToTranslate(const std::string&);
  std::string toAddress(const int&);

  void toNew(const std::string&);
  void toLabels(const std::string&);
  void toAddresses(const std::string&);
  std::string changeCommands(const std::string&);
  void toBinary(const std::string&);
  void work(const std::string&);

private:
  std::string working_dir;
  //std::string working_file;
};

#endif //INTERPRETER_H
