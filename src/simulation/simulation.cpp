#include "simulation.h"

using namespace LGen;

void Simulation::setEnvironment(std::unique_ptr<const Environment> environment) {
	this->environment = std::move(environment);
}

const Environment& Simulation::getEnvironment() const {
	return *environment;
}
