#include "command.h"

using namespace LGen;

Command::Command(const std::vector<std::string> triggers) :
	triggers(triggers) {

}

bool Command::apply(const Input &input) {
	if(!applicable(input.getKeyword()))
		return false;

	application(input.getArguments());

	return true;
}

bool Command::applicable(const std::string input) const {
	for(const std::string trigger : triggers)
		if(trigger == input)
			return true;

	return false;
}