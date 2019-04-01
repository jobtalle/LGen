#include <utility>
#include "console/command.h"
#include "console/commandList.h"
#include "console/console.h"

using namespace LGen;

const std::string CommandList::ENUMERATE_PREFIX = "- ";

CommandList::CommandList(std::vector<std::shared_ptr<Command>> commands) :
	commands(std::move(commands)) {

}

bool CommandList::apply(const Input &input, Console &console) const {
	for(auto const &command : commands)
		if(command->apply(input, console))
			return true;

	return false;
}

const std::vector<std::shared_ptr<Command>> &CommandList::getCommands() const {
	return commands;
}

void CommandList::enumerateKeywords(Console &console) const {
	for(auto const &command : commands) {
		std::string keywords = command->getTrigger();
		const std::vector<std::string> aliases = command->getAliases();

		if(!aliases.empty()) {
			keywords += " (";

			for(size_t alias = 0; alias < aliases.size(); ++alias) {
				keywords += aliases[alias];

				if(alias != aliases.size() - 1)
					keywords += ", ";
			}

			keywords += ')';
		}

		console << ENUMERATE_PREFIX << keywords << std::endl;
	}
}