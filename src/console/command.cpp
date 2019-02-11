#include "console/command.h"

using namespace LGen;

const std::string Command::MSG_HELP_LIST = "Available commands:";
const std::string Command::MSG_NEED_MORE_ARGUMENTS = "This command needs more arguments.";

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
			
			else if(input.getKeyword()[trigger.size()] == '?') {
				if(commandList) {
					console.log(MSG_HELP_LIST);
					
					commandList->enumerateKeywords(console);
				}
				else if(hasHelp)
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

void Command::application(const Console &console, const std::vector<std::string> arguments) {
	console.log(MSG_NEED_MORE_ARGUMENTS);
}

void Command::showHelp(const Console &console) const {
	console.dumpFile(help);
}