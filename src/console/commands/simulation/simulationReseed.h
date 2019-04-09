#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::Reseed final : public Command {
	public:
		Reseed();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
	};
}