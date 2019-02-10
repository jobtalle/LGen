#include "console/command.h"

using namespace LGen;

Command::Command(Console *console, const std::vector<std::string> triggers, const std::string help) :
	console(console),
	triggers(triggers),
	help(help),
	hasHelp(true) {

}

Command::Command(Console *console, const std::vector<std::string> triggers) :
	console(console),
	triggers(triggers),
	hasHelp(false) {

}

bool Command::apply(const Input &input) {
	for(const std::string trigger : triggers) {
		if(input.getKeyword().rfind(trigger, 0) == 0) {
			if(input.getKeyword().size() == trigger.size()) {
				application(input.getArguments());

				return true;
			}
			
			if(hasHelp && input.getKeyword()[trigger.size()] == '?') {
				showHelp();

				return true;
			}
		}
	}

	return false;
}

std::string Command::getTrigger() const {
	return triggers[0];
}

std::vector<std::string> Command::getAliases() const {
	std::vector<std::string> aliases;

	for(unsigned int i = 1; i < triggers.size(); ++i)
		aliases.push_back(triggers[i]);

	return aliases;
}

Console *Command::getConsole() {
	return console;
}

void Command::showHelp() {
	console->dumpFile(help);
}