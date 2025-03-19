#ifndef COMPUTER_H
#define COMPUTER_H

#include "parts/inc/cpu.h"
#include "parts/inc/bus.h"
#include "parts/inc/ram.h"
#include "parts/inc/gpu.h"
#include "parts/inc/chipset.h"

#include <iostream> //for debug test

class Computer
{
public:
  Computer(const std::string&);

  void changePath(const std::string&);

  void start(); //only gpu out
  void log(); //commands
  void debug();  //commands and dumps

private:
  Cpu* cpu;
  Bus* bus;
  Ram* ram;
  Gpu* gpu;
  Chipset* chipset;
};

#endif //COMPUTER_H
