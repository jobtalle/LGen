#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::Density final : public Command {
	public:
		Density();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
		static const std::string MSG_RANGE;
		static const unsigned char ARG_DENSITY = 0;
		static const float DENSITY_MIN;
		static const float DENSITY_MAX;
	};
}