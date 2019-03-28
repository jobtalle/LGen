#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Simulation final : public Command {
	public:
		Simulation();

		class New;
		class Delete;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
	};
}