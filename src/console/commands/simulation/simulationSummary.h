#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::Summary final : public Command {
	public:
		Summary();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
		static const std::string MSG_PREFIX_GENERATION;
		static const std::string MSG_PREFIX_AGENTS;
	};
}