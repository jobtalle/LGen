#include "console/commands/help.h"

using namespace LGen;

const std::string Command::Help::KEYWORD = "help";
const std::string Command::Help::FILE = "text/help.txt";
const std::string Command::Help::PREFIX_COMMAND = "- ";

Command::Help::Help(Console *console) :
	Command(console, { KEYWORD }) {

}

void Command::Help::application(const std::vector<std::string> arguments) {
	getConsole()->dumpFile(FILE);

	for(const std::string command : getConsole()->getCommands())
		getConsole()->log(PREFIX_COMMAND + command);
}