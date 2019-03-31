#include "simulation.h"

using namespace LGen;

Simulation::Simulation(std::unique_ptr<const State> initial) :
	initial(std::move(initial)),
	generation(0) {
	
}

Simulation::Simulation(std::unique_ptr<const State> initial, std::unique_ptr<const State> state, const size_t generation) :
	initial(std::move(initial)),
	state(std::move(state)),
	generation(generation) {

}

const State &Simulation::getInitial() const {
	return *initial;
}

const State &Simulation::getState() const {
	if(state)
		return *state;

	return *initial;
}

size_t Simulation::getGeneration() const {
	return generation;
}