#pragma once

#include "console/input.h"
#include "console/console.h"

#include <vector>
#include <string>

namespace LGen {
	class Command {
	public:
		Command(const std::vector<std::string> triggers, const std::string help);
		Command(const std::vector<std::string> triggers);
		bool apply(const Console &console, const Input &input);
		const std::string &getTrigger() const;
		std::vector<std::string> getAliases() const;

		class Exit;
		class Help;

	protected:
		virtual void application(const Console &console, const std::vector<std::string> arguments) = 0;

	private:
		const bool hasHelp;
		const std::vector<std::string> triggers;
		const std::string help;

		void showHelp(const Console &console) const;
	};
};