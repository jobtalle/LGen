#include "console/command.h"

using namespace LGen;

Command::Command(const std::vector<std::string> triggers) :
	triggers(triggers),
	hasHelp(false) {

}

Command::Command(const std::vector<std::string> triggers, const std::string help) :
	triggers(triggers),
	help(help),
	hasHelp(true) {

}

Command::Command(const std::vector<std::string> triggers, const std::vector<Command*> commands) :
	triggers(triggers),
	hasHelp(true),
	commandList(new CommandList(commands)) {

}

bool Command::apply(const Console &console, const Input &input) {
	for(const std::string trigger : triggers) {
		if(input.getKeyword().rfind(trigger, 0) == 0) {
			if(input.getKeyword().size() == trigger.size()) {
				application(console, input.getArguments());

				return true;
			}
			
			if(hasHelp && input.getKeyword()[trigger.size()] == '?') {
				showHelp(console);

				return true;
			}
		}
	}

	return false;
}

const std::string &Command::getTrigger() const {
	return triggers[0];
}

std::vector<std::string> Command::getAliases() const {
	std::vector<std::string> aliases;

	for(auto trigger = triggers.begin() + 1; trigger < triggers.end(); ++trigger)
		aliases.push_back(*trigger);

	return aliases;
}

void Command::showHelp(const Console &console) const {
	console.dumpFile(help);
}