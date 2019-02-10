#include "console/commands/exit.h"

using namespace LGen;

const std::string Command::Exit::KEYWORD = "exit";
const std::string Command::Exit::FILE_HELP = "text/helpExit.txt";
const std::string Command::Exit::MSG_ARGUMENTS = "The exit command takes no arguments.";

Command::Exit::Exit(Console *console) :
	Command(console, { KEYWORD }, FILE_HELP) {

}

void Command::Exit::application(const std::vector<std::string> arguments) {
	if(arguments.size() == 0)
		getConsole()->stop();
	else
		getConsole()->log(MSG_ARGUMENTS);
}