#include "simulationDensity.h"

using namespace LGen;

const std::string Command::Simulation::Density::KEYWORD = "density";
const std::string Command::Simulation::Density::FILE_HELP = "text/helpSimulationDensity.txt";
const std::string Command::Simulation::Density::MSG_RANGE = "Please enter a density in the range ";
const float Command::Simulation::Density::DENSITY_MIN = 0.1f;
const float Command::Simulation::Density::DENSITY_MAX = 80;

Command::Simulation::Density::Density() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::Density::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const auto density = std::stof(arguments[ARG_DENSITY]);

		if(density < DENSITY_MIN || density > DENSITY_MAX)
			console << MSG_RANGE << '[' << DENSITY_MIN << ", " << DENSITY_MAX << ']' << std::endl;
		else
			workspace.simulation->setDensity(density);
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}
