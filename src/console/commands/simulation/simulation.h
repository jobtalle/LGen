#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Simulation final : public Command {
	public:
		Simulation();

		class New;
		class Delete;
		class Save;
		class Load;
		class Render;
		class Advance;
		class AdvanceN;
		class Revert;
		class Summary;
		class Reseed;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string MSG_NO_SIMULATION;
		static const std::string MSG_INCOMPLETE_ENVIRONMENT;
	};
}