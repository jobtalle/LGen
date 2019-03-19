#include "file.h"
#include "utils/stringUtils.h"

#include <fstream>

using namespace LGen;

const std::string File::CONNECTIVE = ":";
const std::string File::CONNECTIVE_FORMATTED = ": ";
const std::string File::INDENT = "  ";
const std::string File::BLOCK_START = "{";
const char File::BLOCK_CLOSE = '}';

File::File(const std::string &file) {
	std::ifstream source;
	std::string line;
	std::vector<std::string> lines;

	source.open(file, std::fstream::in);

	while(std::getline(source, line))
		lines.push_back(line);

	source.close();

	std::vector<std::string>::const_iterator it = lines.begin();

	while(it != lines.end())
		read(it);
}

File::File(std::vector<std::string>::const_iterator &line) {
	while(line->back() != BLOCK_CLOSE)
		read(line);

	++line;
}

void File::save(const std::string &file) const {
	std::ofstream dest;

	dest.open(file, std::fstream::out);
	dest << *this;
	dest.close();
}

void File::printValues(std::ostream &stream, const std::string &indent) const {
	for(const auto &pair : values)
		stream << indent << pair.first << CONNECTIVE_FORMATTED << pair.second << std::endl;
}

void File::printFiles(std::ostream &stream, const std::string &indent) const {
	for(const auto &pair : files) {
		stream << indent << pair.first << CONNECTIVE_FORMATTED << BLOCK_START << std::endl;

		pair.second.printValues(stream, indent + INDENT);
		pair.second.printFiles(stream, indent + INDENT);

		stream << indent << BLOCK_CLOSE << std::endl;
	}
}

bool File::keyExists(const std::string& key) const {
	return values.find(key) != values.end() || files.find(key) != files.end();
}

void File::set(const std::string &key, const std::string &value) {
	values[key] = value;
}

void File::set(const std::string& key, const float value) {
	values[key] = std::to_string(value);
}

void File::set(const std::string& key, const int value) {
	values[key] = std::to_string(value);
}

void File::set(const std::string &key, const File &file) {
	files[key] = file;
}

std::string File::getString(const std::string &key) const {
	return values.at(key);
}

float File::getFloat(const std::string& key) const {
	return std::stof(values.at(key));
}

int File::getInt(const std::string& key) const {
	return std::stoi(values.at(key));
}

File File::getFile(const std::string &key) const {
	return files.at(key);
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
