#include "simulationSave.h"
#include "file/fileSimulation.h"

using namespace LGen;

const std::string Command::Simulation::Save::KEYWORD = "save";
const std::string Command::Simulation::Save::FILE_HELP = "text/helpSimulationSave.txt";
const std::string Command::Simulation::Save::MSG_ERROR = "Error while saving the simulation.";

Command::Simulation::Save::Save() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::Save::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		File file;

		(file << *workspace.simulation).save(arguments[ARG_FILE]);
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}