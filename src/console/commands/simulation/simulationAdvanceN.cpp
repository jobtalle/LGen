#include "simulationAdvanceN.h"

using namespace LGen;

const std::string Command::Simulation::AdvanceN::KEYWORD = "advance-n";
const std::string Command::Simulation::AdvanceN::FILE_HELP = "text/helpSimulationAdvanceN.txt";
const std::string Command::Simulation::AdvanceN::MSG_ERROR = "Error while parsing the number of generations.";
const std::string Command::Simulation::AdvanceN::MSG_ADVANCED = "Advanced ";

Command::Simulation::AdvanceN::AdvanceN() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::AdvanceN::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	try {
		const size_t count = std::stoi(arguments[ARG_COUNT]);

		for(size_t i = 0; i < count; ++i) {
			workspace.simulation->advance(console);

			console << MSG_ADVANCED << (i + 1) << '/' << count << std::endl;
		}
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}