#include "simulationAdvanceN.h"
#include "utils/timer.h"

using namespace LGen;

const std::string Command::Simulation::AdvanceN::KEYWORD = "advance-n";
const std::string Command::Simulation::AdvanceN::FILE_HELP = "text/helpSimulationAdvanceN.txt";
const std::string Command::Simulation::AdvanceN::MSG_ERROR = "Error while parsing the number of generations.";
const std::string Command::Simulation::AdvanceN::MSG_ADVANCED = "Advanced ";
const std::string Command::Simulation::AdvanceN::MSG_ELAPSED = "Elapsed time: ";

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

	if(!workspace.simulation->getState().getEnvironment().isComplete()) {
		console << MSG_INCOMPLETE_ENVIRONMENT << std::endl;

		return;
	}

	try {
		const size_t count = std::stoi(arguments[ARG_COUNT]);
		Timer timer;

		for(size_t i = 0; i < count; ++i) {
			workspace.simulation->advance(console, workspace.threadCount);

			console << MSG_ADVANCED << (i + 1) << '/' << count << std::endl;
		}

		console << MSG_ELAPSED << timer.get() << 's' << std::endl;
		console.getMonitor()->enqueue(workspace.simulation->getState().getTaskSceneReport(workspace.threadCount));
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}
