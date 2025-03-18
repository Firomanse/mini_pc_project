#ifndef MIASM_H
#define MIASM_H

#include "inc/interpreter.h"

#include <iostream>

class Miasm
{
public:
  Miasm(const std::string&);

  void interpretCode();
private:
  Interpreter* interpreter;
};

#endif //MIASM_H
