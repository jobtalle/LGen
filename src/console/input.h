#pragma once

#include <string>
#include <vector>

namespace LGen {
	class Input final {
	public:
		Input(std::string source);
		std::string getKeyword() const;
		std::vector<std::string> getArguments() const;

	private:
		static const char DELIMITER = ' ';

		std::string keyword;
		std::vector<std::string> arguments;
	};
};