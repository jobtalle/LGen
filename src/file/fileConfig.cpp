#include "file/fileConfig.h"

using namespace LGen::File;

const std::string Config::CONNECTIVE = "=";

Config::Config() {

}

Config::Config(const std::istream &file) {

}

void Config::serialize(const std::ostream &file) const {

}

void Config::set(const std::string &key, const std::string &value) {

}

const std::string &Config::get(const std::string &key) const {
	return "";
}