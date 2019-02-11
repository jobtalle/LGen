#include "console/command.h"
#include "console/commandList.h"

using namespace LGen;

CommandList::CommandList(const std::vector<Command*> &commands) :
	commands(commands) {

}

CommandList::~CommandList() {
	for(auto command : commands)
		delete command;
}

bool CommandList::apply(const Input &input) const {
	for(auto command : commands)
		if(command->apply(input))
			return true;

	return false;
}

const std::vector<Command*> &CommandList::getCommands() const {
	return commands;
}