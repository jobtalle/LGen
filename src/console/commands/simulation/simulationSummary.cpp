#include "simulationSummary.h"

using namespace LGen;

const std::string Command::Simulation::Summary::KEYWORD = "summary";
const std::string Command::Simulation::Summary::ALIAS = "sum";
const std::string Command::Simulation::Summary::FILE_HELP = "text/helpSimulationSummary.txt";
const std::string Command::Simulation::Summary::MSG_PREFIX_GENERATION = "generation: ";
const std::string Command::Simulation::Summary::MSG_PREFIX_AGENTS = "number of agents: ";
const std::string Command::Simulation::Summary::MSG_PREFIX_DENSITY = "plant density: ";

Command::Simulation::Summary::Summary() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::Simulation::Summary::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	console << MSG_PREFIX_GENERATION << std::to_string(workspace.simulation->getGeneration()) << std::endl;
	console << MSG_PREFIX_AGENTS << std::to_string(workspace.simulation->getState().getEnvironment().getAgents().size()) << std::endl;
	console << MSG_PREFIX_DENSITY << std::to_string(workspace.simulation->getDensity()) << std::endl;
}
