#include "console/command.h"
#include "console/commandList.h"
#include "console/console.h"

using namespace LGen;

CommandList::CommandList(const std::vector<Command*> &commands) :
	commands(commands) {

}

CommandList::~CommandList() {
	for(auto command : commands)
		delete command;
}

bool CommandList::apply(const Console &console, const Input &input) const {
	for(auto command : commands)
		if(command->apply(console, input))
			return true;

	return false;
}

const std::vector<Command*> &CommandList::getCommands() const {
	return commands;
}