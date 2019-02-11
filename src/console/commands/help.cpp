#include "console/commands/help.h"

using namespace LGen;

const std::string Command::Help::KEYWORD = "help";
const std::string Command::Help::ALIAS = "?";
const std::string Command::Help::FILE = "text/help.txt";
const std::string Command::Help::PREFIX_COMMAND = "- ";

Command::Help::Help() :
	Command({ KEYWORD, ALIAS }) {

}

void Command::Help::application(const Console &console, const std::vector<std::string> arguments) {
	console.dumpFile(FILE);

	for(const Command *command : console.getCommandList().getCommands()) {
		std::string keywords = command->getTrigger();
		std::vector<std::string> aliases = command->getAliases();

		if(aliases.size()) {
			keywords += " (";

			for(unsigned int i = 0; i < aliases.size(); ++i) {
				keywords += aliases[i];

				if(i != aliases.size() - 1)
					keywords += ", ";
			}

			keywords += ")";
		}

		console.log(PREFIX_COMMAND + keywords);
	}
}