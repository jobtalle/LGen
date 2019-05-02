#include "simulationMutatorPSymbolChanceRotation.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolChanceRotation::KEYWORD = "pSymbolChanceRotation";
const std::string Command::Simulation::Mutator::PSymbolChanceRotation::FILE_HELP = "text/helpSimulationMutatorPSymbolChanceRotation.txt";

Command::Simulation::Mutator::PSymbolChanceRotation::PSymbolChanceRotation() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolChanceRotation::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolChanceRotation(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
