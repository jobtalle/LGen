#include "simulationMutatorPRuleRemove.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PRuleRemove::KEYWORD = "pRuleRemove";
const std::string Command::Simulation::Mutator::PRuleRemove::FILE_HELP = "text/helpSimulationMutatorPRuleRemove.txt";

Command::Simulation::Mutator::PRuleRemove::PRuleRemove() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PRuleRemove::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPRuleRemove(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
