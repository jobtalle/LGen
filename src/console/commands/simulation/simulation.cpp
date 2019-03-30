#include "simulation.h"
#include "console/commands/simulation/simulationNew.h"
#include "console/commands/simulation/simulationDelete.h"
#include "console/commands/simulation/simulationInitialize.h"

using namespace LGen;

const std::string Command::Simulation::KEYWORD = "simulation";
const std::string Command::Simulation::ALIAS = "sim";
const std::string Command::Simulation::MSG_NO_SIMULATION = "No simulation is loaded.";

Command::Simulation::Simulation() :
	Command({ KEYWORD, ALIAS }, {
		std::make_unique<New>(),
		std::make_unique<Delete>(),
		std::make_unique<Initialize>()
	}) {
	
}