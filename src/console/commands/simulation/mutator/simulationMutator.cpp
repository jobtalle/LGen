#include "simulationMutator.h"
#include "simulationMutatorPSymbolAdd.h"
#include "simulationMutatorPSymbolRemove.h"
#include "simulationMutatorPSymbolChanceNew.h"
#include "simulationMutatorPSymbolChanceRotation.h"
#include "simulationMutatorPSymbolChanceSeed.h"
#include "simulationMutatorPSymbolChanceStep.h"
#include "simulationMutatorPSymbolChanceConstant.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::KEYWORD = "mutator";
const std::string Command::Simulation::Mutator::ALIAS = "m";

Command::Simulation::Mutator::Mutator() :
	Command({ KEYWORD, ALIAS }, {
		std::make_unique<PSymbolAdd>(),
		std::make_unique<PSymbolRemove>(),
		std::make_unique<PSymbolChanceNew>(),
		std::make_unique<PSymbolChanceRotation>(),
		std::make_unique<PSymbolChanceSeed>(),
		std::make_unique<PSymbolChanceStep>(),
		std::make_unique<PSymbolChanceConstant>()
	}) {
	
}