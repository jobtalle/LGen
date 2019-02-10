#include "console/commands/help.h"

using namespace LGen;

const std::string Command::Help::KEYWORD = "?";
const std::string Command::Help::FILE = "text/help.txt";

Command::Help::Help(Console *console) :
	Command(console, { KEYWORD }) {

}

void Command::Help::application(const std::vector<std::string> arguments) {
	getConsole()->dumpFile(FILE);
}