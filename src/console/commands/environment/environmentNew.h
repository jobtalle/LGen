#pragma once

#include "console/commands/environment/environment.h"

namespace LGen {
	class Command::Environment::New final : public Command {
	public:
		New();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
	};
}