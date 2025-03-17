#include "../inc/cpu.h"

#define command         ((*array)[0])
#define highest_address ((*array)[1])
#define lowest_address  ((*array)[2])
#define data            ((*array)[3])

Cpu::Cpu(const int& size_) : Component(size_), ComponentBase(size_) //diamond inheritance problem
{
  bus = new Bus(this); //cpu-bus link
}


Bus* Cpu::getBus()
{
  return bus;
}


int Cpu::combineAddress()
{
  return highest_address.toDecimal() * 16 + lowest_address.toDecimal();
}

void Cpu::debug(const bool& debugMode, const std::string& outputData)
{
  if (debugMode)
  {
    std::cout << outputData << std::endl;
  }
}


Cluster Cpu::logicAnd(const Cluster& cluster1, const Cluster& cluster2)
{
  Cluster output;
  for (int i = 0; i < 4; ++i)
  {
    output[i] = cluster1[i] && cluster2[i];
  }
  return output;
}

Cluster Cpu::logicOr(const Cluster& cluster1, const Cluster& cluster2)
{
  Cluster output;
  for (int i = 0; i < 4; ++i)
  {
    output[i] = cluster1[i] || cluster2[i];
  }
  return output;
}

Cluster Cpu::logicAdd(const Cluster& cluster1, const Cluster& cluster2)
{
  Cluster output;
  bool carry = false;
  for (int i = 0; i < 4; ++i)
  {
    if (cluster1[i] && cluster2[i])
    {
      carry = true;
    }
    output[i] = cluster1[i] xor cluster2[i] xor carry;
    carry = false;
  }
  return output;
}

Cluster Cpu::logicSub(const Cluster& cluster1, const Cluster& cluster2)
{
  Cluster output;
  output = cluster2;
  output = logicAdd(cluster1, output.inverse());
  output = logicAdd(output, {0,0,0,1});
  return output;
}


void Cpu::getCommand()
{
  command = bus->readFromMemory(Clock::getNextTick());
}

bool Cpu::executeCommand(const bool& debugMode)
{
  ClusterSet* buffer = new ClusterSet(2);
  switch (command.toDecimal())
  {
    case 0:
      debug(debugMode, "halt");
      return true;
    case 1:
      debug(debugMode, "poweroff");
      return false;
    case 2:
      debug(debugMode, "not");
      data.inverse();
      return true;
    case 3: //swap (not for this processor)

    case 4: //?
    case 5: //?
      debug(debugMode, "unknown command");
      return false;
    case 6:
      debug(debugMode, "set");
      (*buffer)[1] = bus->readFromMemory(Clock::getNextTick());
      (*buffer)[0] = bus->readFromMemory(Clock::getNextTick());
      bus->writeToGpu((*buffer));
      return true;
    case 7:
      debug(debugMode, "write");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      bus->writeToMemory(combineAddress(), data);
      return true;

    case 8:
      debug(debugMode, "and");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      data = logicAnd(data, bus->readFromMemory(combineAddress()));
      return true;
    case 9:
      debug(debugMode, "or");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      data = logicOr(data, bus->readFromMemory(combineAddress()));
      return true;
    case 10:
      debug(debugMode, "add");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      data = logicAdd(data, bus->readFromMemory(combineAddress()));
      return true;
    case 11:
      debug(debugMode, "sub");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      data = logicSub(data, bus->readFromMemory(combineAddress()));
      return true;

    case 12:
    jump:
      debug(debugMode, "jump");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      Clock::setTime(combineAddress());
      return true;
    case 13:
      debug(debugMode, "jz");
      if (data.toDecimal() == 0) { goto jump; }
    case 14:
      debug(debugMode, "get");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      (*buffer) = bus->readFromKeyboard();
      bus->writeToMemory(combineAddress(), (*buffer)[0]);
      bus->writeToMemory(combineAddress() + 1, (*buffer)[1]);
      return true;
    case 15:
      debug(debugMode, "read");
      highest_address = bus->readFromMemory(Clock::getNextTick());
      lowest_address = bus->readFromMemory(Clock::getNextTick());
      data = bus->readFromMemory(combineAddress());
      return true;
  }
  //error
  return false;
}
