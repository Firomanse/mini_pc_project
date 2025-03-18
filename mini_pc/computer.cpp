#include "computer.h"

Computer::Computer(const std::string& working_dir)
{
  cpu = new Cpu(4);
  bus = cpu->getBus();
  ram = new Ram(256, working_dir);
  gpu = new Gpu(2);
  chipset = new Chipset(2);

  bus->link(ram, 'm');
  bus->link(gpu, 'g');
  bus->link(chipset, 'i');

  Clock::setSize(256);

  ram->readPreset("new_program");
}

void Computer::start()
{
  bool is_powered_on = true;
  for (;;)
  {
    cpu->getCommand();
    is_powered_on = cpu->executeCommand(0);
    if (!is_powered_on) { break; }
  }
}

void Computer::log()
{
  bool is_powered_on = true;
  for (;;)
  {
    cpu->getCommand();
    is_powered_on = cpu->executeCommand(1);
    if (!is_powered_on) { break; }
  }
}

void Computer::debug()
{
  bool is_powered_on = true;
  std::cout << "ram dump" << std::endl;
  ram->showDump();
  for (;;)
  {
    std::cout << "cpu dump" << std::endl;
    cpu->showDump();
    cpu->getCommand();
    is_powered_on = cpu->executeCommand(1);
    if (!is_powered_on) { break; }

    std::cout << "enter any key to continue debug" << std::endl;
    std::string tmp;
    std::cin >> tmp;
  }
  std::cout << "ram dump" << std::endl;
  ram->showDump();
}
