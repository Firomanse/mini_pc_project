#include "miasm.h"

Miasm::Miasm(const std::string& working_dir)
{
  interpreter = new Interpreter(working_dir);
  ram_translator = new RamTranslator(working_dir);
}

void Miasm::assembly()
{
  inputWorkingFile();
  interpretCode();
  translateToRam();
}

void Miasm::inputWorkingFile()
{
  std::cout << "Please, input file name" << std::endl;
  std::cin >> working_file;
}

void Miasm::interpretCode()
{
  interpreter->work(working_file);
  std::cout << working_file << " had been translated to code" << '\n'
            << "(you can find it in mini_asm/code/output)" << std::endl;
}

void Miasm::translateToRam()
{
  ram_translator->work(working_file);
  std::cout << working_file << " had been translated to ram" << '\n'
            << "(you can find it in firmware/mem_dump)" << std::endl;
}
