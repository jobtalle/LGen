#include "simulationAdvance.h"

using namespace LGen;

const std::string Command::Simulation::Advance::KEYWORD = "advance";
const std::string Command::Simulation::Advance::ALIAS = "++";
const std::string Command::Simulation::Advance::FILE_HELP = "text/helpSimulationAdvance.txt";

Command::Simulation::Advance::Advance() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::Simulation::Advance::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	workspace.simulation->advance(console);
}
