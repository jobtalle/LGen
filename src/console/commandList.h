#pragma once

#include "console/input.h"

#include <vector>

namespace LGen {
	class Command;
	class CommandList final {
	public:
		CommandList(const std::vector<Command*> &commands);
		~CommandList();
		bool apply(const Input &input) const;
		const std::vector<Command*> &getCommands() const;

	private:
		const std::vector<Command*> commands;
	};
};