#include "simulationMutatorPSymbolAdd.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolAdd::KEYWORD = "pSymbolAdd";
const std::string Command::Simulation::Mutator::PSymbolAdd::FILE_HELP = "text/helpSimulationMutatorPSymbolAdd.txt";

Command::Simulation::Mutator::PSymbolAdd::PSymbolAdd() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::Mutator::PSymbolAdd::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolAdd(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
