#include "miasm.h"

Miasm::Miasm(const std::string& working_dir)
{
  interpreter = new Interpreter(working_dir);
}

void Miasm::interpretCode()
{
  std::string working_file;
  std::cout << "Please, input file name" << std::endl;
  std::cin >> working_file;
  interpreter->work(working_file);
  std::cout << working_file << " had been translated" << '\n'
            << "(you can find it in mini_asm/code/output)" << std::endl;
}
