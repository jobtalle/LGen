#include "command.h"

using namespace LGen;

Command::Command(Console *console, const std::vector<std::string> triggers, const std::string help) :
	console(console),
	triggers(triggers),
	help(help) {

}

bool Command::apply(const Input &input) {
	for(const std::string trigger : triggers) {
		if(input.getKeyword().rfind(trigger, 0) == 0) {
			if(input.getKeyword().size() == trigger.size()) {
				application(input.getArguments());

				return true;
			}
			
			if(input.getKeyword()[trigger.size()] == '?') {
				showHelp();

				return true;
			}
		}
	}

	return false;
}

Console *Command::getConsole() {
	return console;
}

void Command::showHelp() {
	console->dumpFile(help);
}