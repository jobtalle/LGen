#include "simulation.h"
#include "console/commands/simulation/simulationNew.h"
#include "console/commands/simulation/simulationDelete.h"

using namespace LGen;

const std::string Command::Simulation::KEYWORD = "simulation";
const std::string Command::Simulation::ALIAS = "sim";

Command::Simulation::Simulation() :
	Command({ KEYWORD, ALIAS }, {
		std::make_unique<New>(),
		std::make_unique<Delete>()
	}) {
	
}