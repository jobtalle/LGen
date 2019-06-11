#include "simulationMutatorPSymbolRemove.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolRemove::KEYWORD = "pSymbolRemove";
const std::string Command::Simulation::Mutator::PSymbolRemove::FILE_HELP = "text/helpSimulationMutatorPSymbolRemove.txt";

Command::Simulation::Mutator::PSymbolRemove::PSymbolRemove() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolRemove::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolRemove(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
