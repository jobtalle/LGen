#include "simulationAdvance.h"

using namespace LGen;

const std::string Command::Simulation::Advance::KEYWORD = "advance";
const std::string Command::Simulation::Advance::ALIAS = "++";
const std::string Command::Simulation::Advance::FILE_HELP = "text/helpSimulationAdvance.txt";

Command::Simulation::Advance::Advance() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::Simulation::Advance::application(
	const std::vector<std::string> &arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	if(!workspace.simulation->getState().getEnvironment().isComplete()) {
		console << MSG_INCOMPLETE_ENVIRONMENT << std::endl;

		return;
	}

	workspace.simulation->advance(console, workspace.threadCount);

	console.getMonitor()->enqueue(workspace.simulation->getState().getTaskScene(workspace.threadCount));
}
