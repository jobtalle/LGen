#include "simulationMutatorPBranchRemove.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PBranchRemove::KEYWORD = "pBranchRemove";
const std::string Command::Simulation::Mutator::PBranchRemove::FILE_HELP = "text/helpSimulationMutatorPBranchRemove.txt";

Command::Simulation::Mutator::PBranchRemove::PBranchRemove() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PBranchRemove::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPBranchRemove(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
