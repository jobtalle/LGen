#include "file.h"
#include "utils/stringUtils.h"

#include <fstream>

using namespace LGen;

const std::string File::CONNECTIVE = ":";
const std::string File::CONNECTIVE_FORMATTED = ": ";
const std::string File::BLOCK_START = "{";
const std::string File::BLOCK_CLOSE = "}";

File::File(const std::string &file) {
	std::ifstream source;
	std::string line;
	std::vector<std::string> lines;

	source.open(file, std::fstream::in);

	while(std::getline(source, line))
		lines.push_back(line);

	source.close();

	auto it = lines.begin();

	while(it != lines.end())
		read(it);
}

File::File(std::vector<std::string>::const_iterator &line) {
	while(*line != BLOCK_CLOSE)
		read(line);

	++line;
}

void File::save(const std::string &file) const {
	std::ofstream dest;

	dest.open(file, std::fstream::out);
	dest << *this;
	dest.close();
}

void File::printValues(std::ostream &stream) const {
	for(const auto &pair : values)
		stream << pair.first << CONNECTIVE_FORMATTED << pair.second << std::endl;
}

void File::printFiles(std::ostream &stream) const {
	for(const auto &pair : files) {
		stream << pair.first << CONNECTIVE_FORMATTED << BLOCK_START << std::endl;
		stream << pair.second;
		stream << BLOCK_CLOSE << std::endl;
	}
}

void File::set(const std::string &key, const std::string &value) {
	values[key] = value;
}

void File::set(const std::string &key, const File &file) {
	files[key] = file;
}

void File::get(const std::string &key, std::string &value) const {
	value = values.at(key);
}

void File::get(const std::string &key, File &file) const {
	file = files.at(key);
}

void File::read(std::vector<std::string>::const_iterator &line) {
	const auto connective = line->find_first_of(CONNECTIVE);
	const auto key = Utils::String::trim(line->substr(0, connective));
	const auto value = Utils::String::trim(line->substr(connective + CONNECTIVE.size()));

	if(value == BLOCK_START)
		set(key, File(++line));
	else
		++line, set(key, value);
}

std::ostream &operator<<(std::ostream &stream, const File &file) {
	file.printValues(stream);
	file.printFiles(stream);

	return stream;
}