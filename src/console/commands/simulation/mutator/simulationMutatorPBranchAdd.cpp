#include "simulationMutatorPBranchAdd.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PBranchAdd::KEYWORD = "pBranchAdd";
const std::string Command::Simulation::Mutator::PBranchAdd::FILE_HELP = "text/helpSimulationMutatorPBranchAdd.txt";

Command::Simulation::Mutator::PBranchAdd::PBranchAdd() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PBranchAdd::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPBranchAdd(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
