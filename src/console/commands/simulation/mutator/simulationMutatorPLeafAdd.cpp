#include "simulationMutatorPLeafAdd.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PLeafAdd::KEYWORD = "pLeafAdd";
const std::string Command::Simulation::Mutator::PLeafAdd::FILE_HELP = "text/helpSimulationMutatorPLeafAdd.txt";

Command::Simulation::Mutator::PLeafAdd::PLeafAdd() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PLeafAdd::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPLeafAdd(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
