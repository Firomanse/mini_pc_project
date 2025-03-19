#ifndef MIASM_H
#define MIASM_H

#include "inc/interpreter.h"
#include "inc/ram_translator.h"

#include <iostream>

class Miasm
{
public:
  Miasm(const std::string&);

  void changePath(const std::string&);
  void assembly();

  void inputWorkingFile();
  void interpretCode();
  void translateToRam();
private:
  std::string working_file = "";
  Interpreter* interpreter;
  RamTranslator* ram_translator;
};

#endif //MIASM_H
