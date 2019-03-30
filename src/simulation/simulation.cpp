#include "simulation.h"

using namespace LGen;

Simulation::Simulation(const LParse::Randomizer randomizer) :
	randomizer(randomizer) {
	
}

void Simulation::setEnvironment(std::unique_ptr<const Environment> environment) {
	this->environment = std::move(environment);
}

const Environment &Simulation::getEnvironment() const {
	return *environment;
}

const LParse::Randomizer& Simulation::getRandomizer() const {
	return randomizer;
}
