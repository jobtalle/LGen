#include "simulationLoad.h"
#include "file/fileSimulation.h"

using namespace LGen;

const std::string Command::Simulation::Load::KEYWORD = "load";
const std::string Command::Simulation::Load::FILE_HELP = "text/helpSimulationLoad.txt";
const std::string Command::Simulation::Load::MSG_ERROR = "Error while loading the simulation.";

Command::Simulation::Load::Load() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::Load::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	try {
		workspace.simulation << File(arguments[ARG_FILE]);
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}
