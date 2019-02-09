#include "console/commands/exit.h"

#include <iostream>

using namespace LGen;

Command::Exit::Exit(Console *console) :
	Command(console, { "exit" }, "text/helpExit.txt") {

}

void Command::Exit::application(const std::vector<std::string> arguments) {
	getConsole()->stop();
}