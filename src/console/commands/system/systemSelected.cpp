#include "systemSelected.h"

using namespace LGen;

const std::string Command::System::Selected::KEYWORD = "selected";
const std::string Command::System::Selected::FILE_HELP = "text/helpSystemSelected.txt";
const std::string Command::System::Selected::MSG_ERROR = "No system is selected. Ensure a simulation is loaded and an agent is selected.";

Command::System::Selected::Selected() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::System::Selected::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.simulation || console.getMonitor()->getSelected() == -1) {
		console << MSG_ERROR << std::endl;

		return;
	}

	workspace.system = std::make_unique<LParse::System>(
		workspace.simulation->getState().getEnvironment().getAgents()[console.getMonitor()->getSelected()].getSystem());
}
