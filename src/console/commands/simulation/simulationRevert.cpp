#include "simulationRevert.h"

using namespace LGen;

const std::string Command::Simulation::Revert::KEYWORD = "revert";
const std::string Command::Simulation::Revert::FILE_HELP = "text/helpSimulationRevert.txt";

Command::Simulation::Revert::Revert() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::Revert::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	workspace.simulation->revert();
}
