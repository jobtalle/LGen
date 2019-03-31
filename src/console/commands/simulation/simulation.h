#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Simulation final : public Command {
	public:
		Simulation();

		class New;
		class Delete;
		class Initialize;
		class Save;
		class Load;
		class Render;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string MSG_NO_SIMULATION;
	};
}