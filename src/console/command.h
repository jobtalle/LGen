#pragma once

#include "console/input.h"
#include "console/console.h"
#include "console/commandList.h"
#include "workspace/workspace.h"

#include <vector>
#include <string>
#include <memory>

namespace LGen {
	class Command {
	public:
		class Exit;
		class Help;
		class System;

		Command(const std::vector<std::string> triggers, const char args = -1);
		Command(const std::vector<std::string> triggers, const std::string help, const char args = -1);
		Command(const std::vector<std::string> triggers, const std::vector<Command*> commands, const char args = -1);
		virtual ~Command() = default;
		bool apply(const Input &input, Console &console, Workspace &workspace);
		const std::string &getTrigger() const;
		std::vector<std::string> getAliases() const;

	protected:
		virtual void application(
			const std::vector<std::string> arguments,
			Console &console,
			Workspace &workspace);

	private:
		static const std::string MSG_HELP_LIST;
		static const std::string MSG_NEED_MORE_ARGUMENTS;
		static const std::string MSG_THIS_COMMAND_TAKES;
		static const std::string MSG_ARGUMENT;
		static const std::string MSG_ARGUMENTS;
		static const std::string MSG_INVALID_INPUT;

		const char args;
		const bool hasHelp;
		const std::vector<std::string> triggers;
		const std::string help;
		std::unique_ptr<CommandList> commandList;

		void showHelp(const Console &console) const;
	};
};