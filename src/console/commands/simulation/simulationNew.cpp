#include "simulationNew.h"

using namespace LGen;

const std::string Command::Simulation::New::KEYWORD = "new";
const std::string Command::Simulation::New::FILE_HELP = "text/helpSimulationNew.txt";

Command::Simulation::New::New() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::New::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	workspace.simulation = std::make_unique<LGen::Simulation>();
}