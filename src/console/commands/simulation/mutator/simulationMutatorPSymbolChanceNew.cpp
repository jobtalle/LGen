#include "simulationMutatorPSymbolChanceNew.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolChanceNew::KEYWORD = "pSymbolChanceNew";
const std::string Command::Simulation::Mutator::PSymbolChanceNew::FILE_HELP = "text/helpSimulationMutatorPSymbolChanceNew.txt";

Command::Simulation::Mutator::PSymbolChanceNew::PSymbolChanceNew() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolChanceNew::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolChanceNew(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
