#include "simulation.h"

using namespace LGen;

Simulation::Simulation(
	std::unique_ptr<Mutator> mutator,
	std::unique_ptr<const State> initial) :
	mutator(std::move(mutator)),
	initial(std::move(initial)),
	generation(0) {
	
}

Simulation::Simulation(
	std::unique_ptr<Mutator> mutator,
	std::unique_ptr<const State> initial,
	std::unique_ptr<const State> state,
	const size_t generation) :
	mutator(std::move(mutator)),
	initial(std::move(initial)),
	state(std::move(state)),
	generation(generation) {

}

Mutator &Simulation::getMutator() const {
	return *mutator;
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

void Simulation::advance(Console &console) {
	LParse::Randomizer randomizer = getState().getRandomizer();
	const auto task = getState().getTaskSceneReport(&randomizer);

	console.getMonitor()->enqueue(task);

	const auto report = task->getReport();
	auto environment = getState().getEnvironment().makeEmptyCopy();



	state = std::make_unique<State>(std::move(environment), randomizer);
	++generation;
}

void Simulation::revert() {
	generation = 0;
	state = nullptr;
}