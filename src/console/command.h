#pragma once

#include "input.h"
#include "console.h"

#include <vector>
#include <string>

namespace LGen {
	class Command {
	public:
		Command(Console *console, const std::vector<std::string> triggers, const std::string help);
		bool apply(const Input &input);

		class Exit;

	protected:
		virtual void application(const std::vector<std::string> input) = 0;
		Console *getConsole();

	private:
		Console *console;
		const std::vector<std::string> triggers;
		const std::string help;

		void showHelp();
	};
};