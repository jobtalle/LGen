#include "simulationNew.h"

using namespace LGen;

const std::string Command::Simulation::New::KEYWORD = "new";
const std::string Command::Simulation::New::FILE_HELP = "text/helpSimulationNew.txt";
const std::string Command::Simulation::New::MSG_NO_ENVIRONMENT = "No environment is loaded, an environment is required to initialize the simulation.";

Command::Simulation::New::New() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::New::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	workspace.simulation = std::make_unique<LGen::Simulation>(
		std::make_unique<LGen::Mutator>(),
		std::make_unique<Utility>(),
		std::make_unique<State>(
			std::make_unique<const LGen::Environment>(*workspace.environment),
			workspace.randomizer));
}