#include "simulationDelete.h"

using namespace LGen;

const std::string Command::Simulation::Delete::KEYWORD = "delete";
const std::string Command::Simulation::Delete::FILE_HELP = "text/helpSimulationDelete.txt";

Command::Simulation::Delete::Delete() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::Delete::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	workspace.simulation = nullptr;
}