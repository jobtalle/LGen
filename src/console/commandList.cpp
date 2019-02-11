#include "console/command.h"
#include "console/commandList.h"
#include "console/console.h"

using namespace LGen;

const std::string CommandList::ENUMERATE_PREFIX = "- ";

CommandList::CommandList(const std::vector<Command*> &commands) :
	commands(commands) {

}

CommandList::~CommandList() {
	for(auto const command : commands)
		delete command;
}

bool CommandList::apply(const Console &console, const Input &input) const {
	for(auto const command : commands) {
		if(command->apply(console, input))
			return true;
	}

	return false;
}

const std::vector<Command*> &CommandList::getCommands() const {
	return commands;
}

void CommandList::enumerateKeywords(const Console &console) const {
	for(auto const command : commands) {
		std::string keywords = command->getTrigger();
		const std::vector<std::string> &aliases = command->getAliases();

		if(aliases.size()) {
			keywords += " (";

			for(size_t alias = 0; alias < aliases.size(); ++alias) {
				keywords += aliases[alias];

				if(alias != aliases.size() - 1)
					keywords += ", ";
			}

			keywords += ')';
		}

		console.log(ENUMERATE_PREFIX + keywords);
	}
}