#include "simulationMutatorPRuleDuplicate.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PRuleDuplicate::KEYWORD = "pRuleDuplicate";
const std::string Command::Simulation::Mutator::PRuleDuplicate::FILE_HELP = "text/helpSimulationMutatorPRuleDuplicate.txt";

Command::Simulation::Mutator::PRuleDuplicate::PRuleDuplicate() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PRuleDuplicate::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPRuleDuplicate(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
