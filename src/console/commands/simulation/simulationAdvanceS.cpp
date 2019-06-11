#include "simulationAdvanceS.h"
#include "utils/timer.h"
#include "file/fileSimulation.h"

using namespace LGen;

const std::string Command::Simulation::AdvanceS::KEYWORD = "advance-s";
const std::string Command::Simulation::AdvanceS::FILE_HELP = "text/helpSimulationAdvanceS.txt";
const std::string Command::Simulation::AdvanceS::MSG_ERROR = "Error while parsing the number of seconds.";
const std::string Command::Simulation::AdvanceS::MSG_ADVANCED = "Advanced ";
const std::string Command::Simulation::AdvanceS::MSG_OUT_OF_RANGE = "The number of seconds must be in the range ";
const std::string Command::Simulation::AdvanceS::MSG_LEFT = "s left.";
const float Command::Simulation::AdvanceS::TIME_MIN = 1;
const float Command::Simulation::AdvanceS::TIME_MAX = 100000;

Command::Simulation::AdvanceS::AdvanceS() :
	Command({ KEYWORD }, FILE_HELP, 1) {
	
}

void Command::Simulation::AdvanceS::application(
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
		const auto seconds = std::stof(arguments[ARG_SECONDS]);

		if(seconds < TIME_MIN || seconds > TIME_MAX) {
			console << MSG_OUT_OF_RANGE << '[' << TIME_MIN << ", " << TIME_MAX << ']' << std::endl;

			return;
		}

		Timer timer;
		size_t generation = 0;
		double time;

		const size_t saveInterval = 1000;
		size_t saveCountdown = saveInterval;

		while((time = timer.get()) < seconds) {
			workspace.simulation->advance(console, workspace.threadCount);

			console << MSG_ADVANCED << ++generation << ", " << (seconds - time) << MSG_LEFT << std::endl;

			if(--saveCountdown == 0) {
				saveCountdown = saveInterval;

				File file;

				(file << *workspace.simulation).save("intervals/gen-" + std::to_string(generation));
			}
		}

		console.getMonitor()->enqueue(workspace.simulation->getState().getTaskSceneReport(workspace.threadCount, true));
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}
