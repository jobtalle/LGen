#include "simulationMutatorPSymbolChanceStep.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolChanceStep::KEYWORD = "pSymbolChanceStep";
const std::string Command::Simulation::Mutator::PSymbolChanceStep::FILE_HELP = "text/helpSimulationMutatorPSymbolChanceStep.txt";

Command::Simulation::Mutator::PSymbolChanceStep::PSymbolChanceStep() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolChanceStep::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolChanceStep(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
