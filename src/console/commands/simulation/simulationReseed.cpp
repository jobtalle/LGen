#include "simulationReseed.h"

using namespace LGen;

const std::string Command::Simulation::Reseed::KEYWORD = "reseed";
const std::string Command::Simulation::Reseed::FILE_HELP = "text/helpSimulationReseed.txt";

Command::Simulation::Reseed::Reseed() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::Reseed::application(
	const std::vector<std::string> &arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	workspace.simulation->reseed();
}
