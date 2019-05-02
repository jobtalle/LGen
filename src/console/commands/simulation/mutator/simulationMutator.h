#pragma once

#include "console/commands/simulation/simulation.h"

namespace LGen {
	class Command::Simulation::Mutator final : public Command {
	public:
		Mutator();

		class PSymbolAdd;
		class PSymbolRemove;
		class PSymbolChanceNew;
		class PSymbolChanceRotation;
		class PSymbolChanceSeed;
		class PSymbolChanceStep;
		class PSymbolChanceConstant;
		class PBranchAdd;
		class PBranchRemove;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
	};
}