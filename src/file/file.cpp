#include "file.h"
#include "utils/stringUtils.h"

#include <fstream>
#include <iostream>

using namespace LGen::File;

const std::string File::CONNECTIVE = ":";
const std::string File::CONNECTIVE_FORMATTED = ": ";

File::File() {

}

File::File(const std::string &file) {
	std::ifstream source;
	std::string line;

	source.open(file, std::fstream::in);

	while(std::getline(source, line))
		readLine(line);

	source.close();
}

void File::save(const std::string &file) const {
	std::ofstream dest;

	dest.open(file, std::fstream::out);

	for(auto pair = pairs.begin(); pair != pairs.end(); ++pair)
		dest << pair->first << CONNECTIVE_FORMATTED << pair->second << std::endl;

	dest.close();
}

void File::set(const std::string &key, const std::string &value) {
	pairs[key] = value;
}

const std::string File::get(const std::string &key) const {
	if(pairs.find(key) == pairs.end())
		return "";
	
	return pairs.at(key);
}

void File::readLine(const std::string &line) {
	auto connective = line.find_first_of(CONNECTIVE);

	if(connective == std::string::npos)
		return;

	set(
		Utils::String::trim(line.substr(0, connective)),
		Utils::String::trim(line.substr(connective + CONNECTIVE.size())));
}
