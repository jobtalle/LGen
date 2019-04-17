#include "simulation.h"
#include "console/commands/simulation/simulationNew.h"
#include "console/commands/simulation/simulationDelete.h"
#include "console/commands/simulation/simulationSave.h"
#include "console/commands/simulation/simulationLoad.h"
#include "console/commands/simulation/simulationRender.h"
#include "console/commands/simulation/simulationAdvance.h"
#include "console/commands/simulation/simulationAdvanceN.h"
#include "console/commands/simulation/simulationRevert.h"
#include "console/commands/simulation/simulationSummary.h"
#include "console/commands/simulation/simulationReseed.h"
#include "console/commands/simulation/simulationDensity.h"

using namespace LGen;

const std::string Command::Simulation::KEYWORD = "simulation";
const std::string Command::Simulation::ALIAS = "sim";
const std::string Command::Simulation::MSG_NO_SIMULATION = "No simulation is loaded.";
const std::string Command::Simulation::MSG_INCOMPLETE_ENVIRONMENT = "The simulation environment is not complete.";

Command::Simulation::Simulation() :
	Command({ KEYWORD, ALIAS }, {
		std::make_unique<New>(),
		std::make_unique<Delete>(),
		std::make_unique<Save>(),
		std::make_unique<Load>(),
		std::make_unique<Render>(),
		std::make_unique<Advance>(),
		std::make_unique<AdvanceN>(),
		std::make_unique<Revert>(),
		std::make_unique<Summary>(),
		std::make_unique<Reseed>(),
		std::make_unique<Density>()
	}) {
	
}