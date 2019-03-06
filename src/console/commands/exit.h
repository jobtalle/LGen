#pragma once

#include "console/console.h"
#include "console/command.h"

namespace LGen {
	class Command::Exit final : public Command{
	public:
		Exit(Console *console);

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;

		Console *console;
	};
}