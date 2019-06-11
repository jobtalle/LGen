#include "simulation.h"
#include "simulation/candidate.h"
#include "simulation/planter.h"

using namespace LGen;

const float Simulation::DENSITY_DEFAULT = 18;

Simulation::Simulation(
	std::unique_ptr<Mutator> mutator,
	std::unique_ptr<Utility> utility,
	std::unique_ptr<State> initial) :
	mutator(std::move(mutator)),
	utility(std::move(utility)),
	initial(std::move(initial)),
	generation(0) {
	
}

Simulation::Simulation(
	std::unique_ptr<Mutator> mutator,
	std::unique_ptr<Utility> utility,
	std::unique_ptr<State> initial,
	std::unique_ptr<State> state,
	const size_t generation) :
	mutator(std::move(mutator)),
	utility(std::move(utility)),
	initial(std::move(initial)),
	state(std::move(state)),
	generation(generation) {

}

Mutator &Simulation::getMutator() const {
	return *mutator;
}

Utility &Simulation::getUtility() const {
	return *utility;
}

const State &Simulation::getInitial() const {
	return *initial;
}

const State &Simulation::getState() const {
	if(state)
		return *state;

	return *initial;
}

float Simulation::getDensity() const {
	return density;
}

size_t Simulation::getGeneration() const {
	return generation;
}

void Simulation::setDensity(const float density) {
	this->density = density;
}

void Simulation::advance(Console &console, const size_t threads) {
	auto randomizer = getState().getRandomizer();
	const auto task = getState().getTaskSceneReport(threads, false, &randomizer);

	console.getMonitor()->enqueue(task);

	const auto report = task->getReport();
	const auto planter = Planter(getState().getEnvironment().getAgents(), report->getAgents(), *utility, randomizer);
	auto environment = getState().getEnvironment().makeEmptyCopy();

	planter.plant(*environment, *mutator, density, randomizer);

	state = std::make_unique<State>(std::move(environment), randomizer);
	++generation;
}

void Simulation::revert() {
	state = nullptr;
	generation = 0;
}

void Simulation::reseed() {
	if(state)
		state->setRandomizer(LParse::Randomizer());
	else
		initial->setRandomizer(LParse::Randomizer());
}