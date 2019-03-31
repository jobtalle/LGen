#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::New final : public Command {
	public:
		New();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_NO_ENVIRONMENT;
	};
}