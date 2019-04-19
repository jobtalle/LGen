#include "simulationRender.h"

using namespace LGen;

const std::string Command::Simulation::Render::KEYWORD = "render";
const std::string Command::Simulation::Render::FILE_HELP = "text/helpSimulationRender.txt";

Command::Simulation::Render::Render() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Simulation::Render::application(
	const std::vector<std::string>& arguments,
	Console& console) {
	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}

	console.getMonitor()->makeVisible();
	console.getMonitor()->enqueue(workspace.simulation->getState().getTaskScene(workspace.threadCount));
}
