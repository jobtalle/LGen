#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::AdvanceS final : public Command {
	public:
		AdvanceS();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_ERROR;
		static const std::string MSG_ADVANCED;
		static const std::string MSG_OUT_OF_RANGE;
		static const std::string MSG_LEFT;
		static const char ARG_SECONDS = 0;
		static const float TIME_MIN;
		static const float TIME_MAX;
	};
}