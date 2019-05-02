#include "simulationMutatorPSymbolChanceConstant.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolChanceConstant::KEYWORD = "pSymbolChanceConstant";
const std::string Command::Simulation::Mutator::PSymbolChanceConstant::FILE_HELP = "text/helpSimulationMutatorPSymbolChanceConstant.txt";

Command::Simulation::Mutator::PSymbolChanceConstant::PSymbolChanceConstant() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolChanceConstant::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolChanceConstant(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
