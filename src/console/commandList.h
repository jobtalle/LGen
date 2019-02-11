#pragma once

#include "console/input.h"

#include <string>
#include <vector>

namespace LGen {
	class Command;
	class Console;
	class CommandList final {
	public:
		CommandList(const std::vector<Command*> &commands);
		~CommandList();
		bool apply(const Console &console, const Input &input) const;
		const std::vector<Command*> &getCommands() const;
		void enumerateKeywords(const Console &console) const;

	private:
		static const std::string ENUMERATE_PREFIX;

		const std::vector<Command*> commands;
	};
};