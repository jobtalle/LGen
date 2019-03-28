#pragma once

#include "console/input.h"

#include <string>
#include <vector>
#include <memory>

namespace LGen {
	class Command;
	class Console;
	class CommandList final {
	public:
		explicit CommandList(std::vector<std::shared_ptr<Command>> commands);
		bool apply(const Input &input, Console &console) const;
		const std::vector<std::shared_ptr<Command>> &getCommands() const;
		void enumerateKeywords(Console &console) const;

	private:
		static const std::string ENUMERATE_PREFIX;

		const std::vector<std::shared_ptr<Command>> commands;
	};
}