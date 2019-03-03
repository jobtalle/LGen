#pragma once

#include "console/input.h"
#include "workspace/workspace.h"

#include <string>
#include <vector>
#include <memory>

namespace LGen {
	class Command;
	class Console;
	class CommandList final {
	public:
		CommandList(const std::vector<std::shared_ptr<Command>> &commands);
		bool apply(const Input &input, Console &console, Workspace &workspace) const;
		const std::vector<std::shared_ptr<Command>> &getCommands() const;
		void enumerateKeywords(Console &console) const;

	private:
		static const std::string ENUMERATE_PREFIX;

		const std::vector<std::shared_ptr<Command>> commands;
	};
};