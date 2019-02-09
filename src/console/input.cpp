#include "input.h"

LGen::Input::Input(std::string source) {
	size_t delimiterPosition = 0;

	while((delimiterPosition = source.find(DELIMITER)) != std::string::npos) {
		arguments.insert(arguments.begin(), source.substr(0, delimiterPosition));

		source.erase(0, delimiterPosition + 1);
	}

	arguments.insert(arguments.begin(), source);

	keyword = arguments[arguments.size() - 1];
}

std::string LGen::Input::getKeyword() const {
	return keyword;
}

std::vector<std::string> LGen::Input::getArguments() const {
	return arguments;
}