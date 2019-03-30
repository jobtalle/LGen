#include "simulationInitialize.h"

using namespace LGen;

const std::string Command::Simulation::Initialize::KEYWORD = "initialize";
const std::string Command::Simulation::Initialize::ALIAS = "init";
const std::string Command::Simulation::Initialize::FILE_HELP = "text/helpSimulationInitialize.txt";
const std::string Command::Simulation::Initialize::MSG_NO_ENVIRONMENT = "No environment is loaded, an environment is required to initialize the simulation.";

Command::Simulation::Initialize::Initialize() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::Simulation::Initialize::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	workspace.simulation->setEnvironment(std::make_unique<LGen::Environment>(*workspace.environment));
}
