#include "simulationMutatorPLeafRemove.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PLeafRemove::KEYWORD = "pLeafRemove";
const std::string Command::Simulation::Mutator::PLeafRemove::FILE_HELP = "text/helpSimulationMutatorPLeafRemove.txt";

Command::Simulation::Mutator::PLeafRemove::PLeafRemove() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PLeafRemove::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPLeafRemove(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
