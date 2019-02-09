#include "command.h"

L::Command::Command(const std::vector<std::string> triggers) :
	triggers(triggers) {

}

bool L::Command::apply(const Input &input) {
	if(!applicable(input.getKeyword()))
		return false;

	application(input.getArguments());

	return true;
}

bool L::Command::applicable(const std::string input) const {
	for(const std::string trigger : triggers)
		if(trigger == input)
			return true;

	return false;
}