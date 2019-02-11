#pragma once

#include "console/input.h"
#include "console/console.h"

#include <vector>
#include <string>

namespace LGen {
	class Command {
	public:
		Command(Console *console, const std::vector<std::string> triggers, const std::string help);
		Command(Console *console, const std::vector<std::string> triggers);
		bool apply(const Input &input);
		const std::string &getTrigger() const;
		std::vector<std::string> getAliases() const;

		class Exit;
		class Help;

	protected:
		virtual void application(const std::vector<std::string> input) = 0;
		Console *getConsole() const;

	private:
		const bool hasHelp;
		Console *console;
		const std::vector<std::string> triggers;
		const std::string help;

		void showHelp() const;
	};
};