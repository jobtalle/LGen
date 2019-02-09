#include "console/commands/exit.h"

#include <iostream>

using namespace LGen;

const std::string Command::Exit::KEYWORD = "exit";
const std::string Command::Exit::FILE_HELP = "text/helpExit.txt";

Command::Exit::Exit(Console *console) :
	Command(console, { KEYWORD }, FILE_HELP) {

}

void Command::Exit::application(const std::vector<std::string> arguments) {
	getConsole()->stop();
}