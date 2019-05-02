#include "inspect.h"
#include "simulation/utility.h"

using namespace LGen;

const std::string Command::Inspect::KEYWORD = "inspect";
const std::string Command::Inspect::FILE_HELP = "text/helpInspect.txt";
const std::string Command::Inspect::MSG_NO_AGENT_SELECTED = "No agent is selected.";
const std::string Command::Inspect::MSG_NO_SIMULATION = "No simulation with a utility function exists.";
const std::string Command::Inspect::MSG_HEAD = "Reporting on agent #";
const std::string Command::Inspect::PROPERTY_INDENT = "  ";
const std::string Command::Inspect::PROPERTY_UTILITY = PROPERTY_INDENT + "Utility: ";
const std::string Command::Inspect::PROPERTY_GENERATIONS = PROPERTY_INDENT + "Generations: ";
const std::string Command::Inspect::PROPERTY_SYMBOLS = PROPERTY_INDENT + "Symbols: ";
const std::string Command::Inspect::PROPERTY_EXPOSURE = PROPERTY_INDENT + "Exposure: ";
const std::string Command::Inspect::PROPERTY_SEEDS = PROPERTY_INDENT + "Seeds: ";

Command::Inspect::Inspect() :
	Command({ KEYWORD }, FILE_HELP, 0) {
	
}

void Command::Inspect::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(console.getMonitor()->getSelected() == -1) {
		console << MSG_NO_AGENT_SELECTED << std::endl;

		return;
	}

	if(!workspace.simulation) {
		console << MSG_NO_SIMULATION << std::endl;

		return;
	}
	
	const auto report = console.getMonitor()->getReport();
	const auto reportAgent = report->getAgents()[console.getMonitor()->getSelected()];

	size_t totalSymbols = 0;

	for(size_t i = 0; i < reportAgent.getGrowthProfile().getProfile().getIterations(); ++i)
		totalSymbols += reportAgent.getGrowthProfile().getProfile().getGrowth(i);
	
	console << MSG_HEAD << console.getMonitor()->getSelected() << std::endl;
	console << PROPERTY_UTILITY << workspace.simulation->getUtility().utility(reportAgent) << std::endl;
	console << PROPERTY_GENERATIONS << reportAgent.getGrowthProfile().getProfile().getIterations() << std::endl;
	console << PROPERTY_SYMBOLS << reportAgent.getSize().getNodes() << '/' << totalSymbols << std::endl;
	console << PROPERTY_EXPOSURE << reportAgent.getExposure().getExposure() << std::endl;
	console << PROPERTY_SEEDS << reportAgent.getSeeds().size() << std::endl;
}
