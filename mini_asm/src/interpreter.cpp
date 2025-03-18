#include "../inc/interpreter.h"

Interpreter::Interpreter(const std::string& working_dir_)
{
  working_dir = working_dir_;
}

std::string Interpreter::toBinaryCode(const std::string& command)
{
  if (command == "halt")     { return "0 0 0 0"; }
  if (command == "poweroff") { return "0 0 0 1"; }
  if (command == "not")      { return "0 0 1 0"; }
  //if (command == "swap?")    { return "0 0 1 1"; }
  //if (command == "?")        { return "0 1 0 0"; }
  //if (command == "?")        { return "0 1 0 1"; }
  if (command == "set")      { return "0 1 1 0"; }
  if (command == "write")    { return "0 1 1 1"; }
  if (command == "and")      { return "1 0 0 0"; }
  if (command == "or")       { return "1 0 0 1"; }
  if (command == "add")      { return "1 0 1 0"; }
  if (command == "sub")      { return "1 0 1 1"; }
  if (command == "jump")     { return "1 1 0 0"; }
  if (command == "jz")       { return "1 1 0 1"; }
  if (command == "get")      { return "1 1 1 0"; }
  if (command == "read")     { return "1 1 1 1"; } 
  return command;
}

void Interpreter::work(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/input/" + working_file);
  output_stream.open(working_dir + "/code/output/" + working_file);

  if (input_stream.is_open())
  {
    std::string command;
    while (input_stream >> command)
    {
      output_stream << toBinaryCode(command) << ' ';
    }
  }
  else
  {
    std::cout << "file hasn't been opened" << std::endl;
  }
}
