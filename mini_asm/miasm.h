#ifndef MIASM_H
#define MIASM_H

#include "inc/interpreter.h"
#include "inc/ram_translator.h"

#include <iostream>

class Miasm
{
public:
  Miasm(const std::string&);

  void interpretCode();
  void translateToRam();
private:
  Interpreter* interpreter;
  RamTranslator* ram_translator;
};

#endif //MIASM_H
