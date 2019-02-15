#include "file/fileConfig.h"
#include "utils/stringUtils.h"

#include <fstream>
#include <iostream>

using namespace LGen::File;

const std::string Config::CONNECTIVE = ":";

Config::Config() {

}

Config::Config(const std::string &file) {
	std::ifstream source;
	std::string line;

	source.open(file);

	while(std::getline(source, line))
		readLine(line);

	source.close();
}

void Config::set(const std::string &key, const std::string &value) {
	pairs[key] = value;
}

const std::string Config::get(const std::string &key) const {
	if(pairs.find(key) == pairs.end())
		return "";
	
	return pairs.at(key);
}

void Config::readLine(const std::string &line) {
	auto connective = line.find_first_of(CONNECTIVE);

	if(connective == std::string::npos)
		return;

	set(
		Utils::String::trim(line.substr(0, connective)),
		Utils::String::trim(line.substr(connective + CONNECTIVE.size())));
}