#include "simulation.h"

using namespace LGen;

void Simulation::setEnvironment(const std::shared_ptr<Environment>& environment) {
	this->environment = environment;
}

const Environment& Simulation::getEnvironment() const {
	return *environment;
}
