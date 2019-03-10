#include <utility>
#include "console/command.h"

using namespace LGen;

const std::string Command::MSG_HELP_LIST = "Available commands:";
const std::string Command::MSG_NEED_MORE_ARGUMENTS = "This command needs more arguments.";
const std::string Command::MSG_THIS_COMMAND_TAKES = "This command needs ";
const std::string Command::MSG_ARGUMENT = " argument.";
const std::string Command::MSG_ARGUMENTS = " arguments.";
const std::string Command::MSG_INVALID_INPUT = "The provided input is invalid.";

Workspace Command::workspace = Workspace::Workspace();

Command::Command(std::vector<std::string> triggers, const char args) :
	triggers(std::move(triggers)),
	hasHelp(false),
	args(args) {

}

Command::Command(std::vector<std::string> triggers, std::string help, const char args) :
	triggers(std::move(triggers)),
	help(std::move(help)),
	hasHelp(true),
	args(args) {

}

Command::Command(std::vector<std::string> triggers, const std::vector<std::shared_ptr<Command>> &commands, const char args) :
	triggers(std::move(triggers)),
	hasHelp(true),
	commandList(std::make_unique<CommandList>(commands)),
	args(args) {

}

bool Command::apply(const Input &input, Console &console) {
	for(const std::string &trigger : triggers) {
		if(input.getKeyword().rfind(trigger, 0) == 0) {
			if(input.getKeyword().size() == trigger.size()) {
				if(commandList && !input.getArguments().empty())
					return commandList->apply(input.getArguments(), console);
				else {
					if(args == -1 || args == input.getArguments().size())
						application(input.getArguments(), console);
					else {
						if(args == 1)
							console << MSG_THIS_COMMAND_TAKES << std::to_string(args) << MSG_ARGUMENT << std::endl;
						else
							console << MSG_THIS_COMMAND_TAKES << std::to_string(args) << MSG_ARGUMENTS << std::endl;
					}
				}

				return true;
			}
			
			else if(input.getKeyword()[trigger.size()] == '?') {
				if(commandList) {
					console << MSG_HELP_LIST << std::endl;
					
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

void Command::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	console << MSG_NEED_MORE_ARGUMENTS << std::endl;
}

void Command::showHelp(const Console &console) const {
	console.dumpFile(help);
}
