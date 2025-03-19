#include <iostream>

#include "mini_pc/computer.h"
#include "mini_asm/miasm.h"

void help();

int main(int argc, char** argv)
{
  system("clear");
  std::cout << "starting mini_pc_project..." << std::endl;
  std::string executed_path(argv[0]);
  std::string working_dir = executed_path.erase(executed_path.rfind('/'));

  Computer computer(working_dir);
  Miasm miasm(working_dir + "/mini_asm");

  std::string arg1 = "";
  if (argc > 1) { arg1 = std::string(argv[1]); }
  std::string arg2 = "";
  if (argc > 2) { arg2 = std::string(argv[2]); }

  switch (argc)
  {
  case 1:
    computer.start();
    break;

  case 2:
  switcher:
    if (arg1 == "-s" || arg1 == "--start")    { computer.start();   break; }
    if (arg1 == "-l" || arg1 == "--log")      { computer.log();     break; }
    if (arg1 == "-d" || arg1 == "--debug")    { computer.debug();   break; }
    //if (arg1 == "-i" || arg1 == "--inspect")  { computer.inspect(); break; }
    //if (arg1 == "-r" || arg1 == "--rebuild")  { computer.rebuild(); break; }
    if (arg1 == "-a" || arg1 == "--assembly") { miasm.assembly();   break; }
    if (arg1 == "-h" || arg1 == "--help")     { help();             break; }

    std::cout << "mini_pc_project: invalid option \'" << argv[1] << "\'" << '\n'
              << "Try \'./mini_pc_project --help\' for more information" << std::endl;
    break;

  case 3:
    if ((arg1 == "-s" || arg1 == "--start")
     || (arg1 == "-l" || arg1 == "--log")
     || (arg1 == "-d" || arg1 == "--debug"))
    {
      computer.changePath(arg2);
      goto switcher;
    }
    std::cout << "mini_pc_project: invalid option \'" << argv[1] << "\'" << '\n'
              << "Try \'./mini_pc_project --help\' for more information" << std::endl;
    break;

  default:
    std::cout << "Too many arguments!" << '\n'
              << "Try \'./mini_pc_project --help\' for more information" << std::endl;
    break;
  }
}

void help()
{
  std::cout << "---Help---"                << '\n'
    << "Usage: ./mini_pc_project [option]" << '\n'
    << "Options:"                          << '\n'
    << "  -s, --start   " << '\t' << "Start mini_pc (default)"    << '\n'
    << "  -l, --log     " << '\t' << "Log mini_pc"                << '\n'
    << "  -d, --debug   " << '\t' << "Debug mini_pc"              << '\n'
    //<< "  -i, --inspect " << '\t' << "Show mini_pc parts"              << '\n'
    //<< "  -r, --rebuild " << '\t' << "Change current mini_pc parts"    << '\n'
    << "  -a, --assembly" << '\t' << "Assembly code files"        << '\n'
    << "  -h, --help    " << '\t' << "Show this help information" << std::endl;
}

