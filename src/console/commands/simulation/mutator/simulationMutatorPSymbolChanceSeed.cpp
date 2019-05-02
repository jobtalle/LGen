#include "simulationMutatorPSymbolChanceSeed.h"

using namespace LGen;

const std::string Command::Simulation::Mutator::PSymbolChanceSeed::KEYWORD = "pSymbolChanceSeed";
const std::string Command::Simulation::Mutator::PSymbolChanceSeed::FILE_HELP = "text/helpSimulationMutatorPSymbolChanceSeed.txt";

Command::Simulation::Mutator::PSymbolChanceSeed::PSymbolChanceSeed() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::Simulation::Mutator::PSymbolChanceSeed::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto probability = std::stof(arguments[ARG_PROBABILITY]);

		workspace.simulation->getMutator().setPSymbolChanceSeed(probability);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
