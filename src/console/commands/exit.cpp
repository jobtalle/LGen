#include "console/commands/exit.h"

using namespace LGen;

const std::string Command::Exit::KEYWORD = "exit";
const std::string Command::Exit::FILE_HELP = "text/helpExit.txt";

Command::Exit::Exit(Console *console) :
	Command({ KEYWORD }, FILE_HELP, 0),
	console(console) {

}

void Command::Exit::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	if(arguments.size() == 0)
		this->console->stop();
	else
		console << MSG_ARGUMENTS << std::endl;
}