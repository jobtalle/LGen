#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::AdvanceN final : public Command {
	public:
		AdvanceN();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
		static const std::string MSG_ERROR;
		static const std::string MSG_ADVANCED;
		static const char ARG_COUNT = 0;
	};
}