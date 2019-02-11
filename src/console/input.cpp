#include "console/input.h"

using namespace LGen;

Input::Input(std::string input) :
	Input(splitInput(input)) {

}

Input::Input(std::vector<std::string> &arguments) {
	keyword = arguments[0];

	for(auto argument = arguments.begin() + 1; argument < arguments.end(); ++argument)
		this->arguments.push_back(*argument);
}

std::string Input::getKeyword() const {
	return keyword;
}

std::vector<std::string> Input::getArguments() const {
	return arguments;
}

std::vector<std::string> Input::splitInput(std::string input) {
	std::vector<std::string> words;
	size_t delimiterPosition = 0;

	while((delimiterPosition = input.find(DELIMITER)) != std::string::npos) {
		words.insert(words.begin(), input.substr(0, delimiterPosition));

		input.erase(0, delimiterPosition + 1);
	}

	words.insert(words.begin(), input);

	return words;
}