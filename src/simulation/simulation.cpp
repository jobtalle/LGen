#include "simulation.h"

using namespace LGen;

Simulation::Simulation(std::unique_ptr<const State> initial) :
	initial(std::move(initial)) {
	
}

Simulation::Simulation(std::unique_ptr<const State> initial, std::unique_ptr<const State> state) :
	initial(std::move(initial)),
	state(std::move(state)) {

}

const State &Simulation::getInitial() const {
	return *initial;
}

const State &Simulation::getState() const {
	if(state)
		return *state;

	return *initial;
}