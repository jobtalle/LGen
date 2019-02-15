#include "utils/stringUtils.h"

using namespace LGen::Utils;

const std::string String::WHITESPACES = " \n\r\t\f\v";

std::string String::ltrim(const std::string &string) {
	const size_t first = string.find_first_not_of(WHITESPACES);

	return first == std::string::npos ? "" : string.substr(first);
};

std::string String::rtrim(const std::string &string) {
	const size_t last = string.find_last_not_of(WHITESPACES);

	return last == std::string::npos ? "" : string.substr(0, last + 1);
};

std::string String::trim(const std::string &string) {
	return ltrim(rtrim(string));
};