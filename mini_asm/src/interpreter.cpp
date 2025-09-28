#include "../inc/interpreter.h"

Interpreter::Interpreter(const std::string& working_dir_)
{
  working_dir = working_dir_;
}

bool Interpreter::isStandardCommand(const std::string& command)
{
  if (command == "halt"
   || command == "poweroff"
   || command == "not"
   || command == "set"
   || command == "write"
   || command == "and"
   || command == "or"
   || command == "add"
   || command == "sub"
   || command == "jump"
   || command == "jz"
   || command == "get"
   || command == "read"
   || command == "0"
   || command == "1")
  {
    return true;
  }
  return false;
}

std::string Interpreter::tryToTranslate(const std::string& command)
{
  try
  {
    int tmp = stoi(command);

    if (tmp >= 0 && tmp < 16)
    {
      std::string out = std::to_string(tmp / 8) + ' ';
      tmp -= (tmp / 8) * 8;
      out            += std::to_string(tmp / 4) + ' ';
      tmp -= (tmp / 4) * 4;
      out            += std::to_string(tmp / 2) + ' ';
      tmp -= (tmp / 2) * 2;
      out            += std::to_string(tmp) + ' ';
      return out;
    }
    return "0 0 0 0 ";
  }
  catch (...)
  {
    return "0 0 0 0 ";
  }
}

std::string Interpreter::toAddress(const int& value)
{
  if (value < 0 || value >= 256)
  {
    return "0 0 0 0 0 0 0 0 "; //error
  }

  int tmp = value;
  std::string out = "";
  for (int i = 128; i > 1; i /= 2)
  {
    out += std::to_string(tmp / i) + ' ';
    tmp -= (tmp / i) * i;
  }
  out += std::to_string(tmp) + ' ';

  return out;
}

void Interpreter::toNew(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/input/" + working_file);
  output_stream.open(working_dir + "/code/new/" + working_file);

  std::vector<DictionaryItem> dictionary;

  if(!input_stream.is_open())
  {
    std::cout << "file hasn't been opened" << std::endl;
  }

  std::string command;
  while (input_stream >> command)
  {
    output_stream << command << ' ';

    if (!isStandardCommand(command))
    {
      bool is_skip = false;
      for (DictionaryItem item : dictionary)
      {
        if (item.label == command)
        {
          is_skip = true;
        }
      }

      if (is_skip)
      {
        continue;
      }

      DictionaryItem new_item;
      new_item.label = command;
      new_item.size  = 2;

      dictionary.push_back(new_item);
    }
  }

  for (DictionaryItem item : dictionary)
  {
    output_stream << "label " << item.label << '\n'
                  << "data "  << item.size  << '\n';
  }
}

void Interpreter::toLabels(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/new/" + working_file);
  output_stream.open(working_dir + "/code/dict/" + working_file);

  std::vector<DictionaryItem> dictionary;

  if (input_stream.is_open())
  {
    std::string command;
    int counter = 0;
    while (input_stream >> command)
    {
      if (command == "label")
      {
        input_stream >> command;
        std::string label = command;
        input_stream >> command;
        if (command == "data")
        {
          input_stream >> command;
          DictionaryItem item;
          item.label = label;
          item.size = stoi(command);
          item.address = counter + (item.size - 1);
          dictionary.push_back(item);

          if (item.size > 1)
          {
            output_stream << "0 0 0 0 ";
          }
          output_stream << tryToTranslate(item.label);

          counter += item.size;
        }
        else
        {
          //error
        }
      }
      else if (isStandardCommand(command))
      {
        output_stream << command << ' ';
        ++counter;
      }
      else
      {
        output_stream << command << ' ';
        counter += 2;
      }
    }
  }
  else
  {
    std::cout << "file hasn't been opened" << std::endl;
  }

  input_stream.close();
  output_stream.close();

  input_stream.open(working_dir + "/code/dict/" + working_file);
  output_stream.open(working_dir + "/code/label/" + working_file);

  if(!input_stream.is_open())
  {
    std::cout << "file hasn't been opened" << std::endl;
  }

  std::string command;
  while (input_stream >> command)
  {
    if (!isStandardCommand(command))
    {
      for (DictionaryItem item : dictionary)
      {
        if (item.label == command)
        {
          output_stream << toAddress(item.address);
        }
      }
    }
    else
    {
      output_stream << command << ' ';
    }
  }
}

void Interpreter::toAddresses(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/label/" + working_file);
  output_stream.open(working_dir + "/code/addr/" + working_file);

  if (input_stream.is_open())
  {
    std::string command;
    while (input_stream >> command)
    {
      if (command == "addr")
      {
        input_stream >> command;
        for (int i = 0; i < 8; ++i)
        {
          output_stream << command[i] << ' ';
        }
      }
      else
      {
        output_stream << command << ' ';
      }
    }
  }
  else
  {
    std::cout << "file hasn't been opened" << std::endl;
  }
}

std::string Interpreter::changeCommands(const std::string& command)
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

void Interpreter::toBinary(const std::string& working_file)
{
  std::ifstream input_stream;
  std::ofstream output_stream;

  input_stream.open(working_dir + "/code/addr/" + working_file);
  output_stream.open(working_dir + "/code/output/" + working_file);

  if (input_stream.is_open())
  {
    std::string command;
    while (input_stream >> command)
    {
      output_stream << changeCommands(command) << ' ';
    }
  }
  else
  {
    std::cout << "file hasn't been opened" << std::endl;
  }
}

void Interpreter::work(const std::string& working_file)
{
  toNew(working_file);
  toLabels(working_file);
  toAddresses(working_file);
  toBinary(working_file);
}
