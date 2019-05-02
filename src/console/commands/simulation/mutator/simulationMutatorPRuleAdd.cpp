#include "simulationMutatorPRuleAdd.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PRuleAdd::KEYWORD = "pRuleAdd";
const std::string Command::Simulation::Mutator::PRuleAdd::FILE_HELP = "text/helpSimulationMutatorPRuleAdd.txt";

Command::Simulation::Mutator::PRuleAdd::PRuleAdd() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PRuleAdd::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPRuleAdd(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
