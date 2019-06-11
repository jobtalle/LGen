#include "fileSimulation.h"
#include "fileState.h"
#include "fileMutator.h"

using namespace LGen;

static const std::string KEY_INITIAL = "initial";
static const std::string KEY_STATE = "state";
static const std::string KEY_GENERATION = "generation";
static const std::string KEY_MUTATOR = "mutator";
static const std::string KEY_DENSITY = "density";

File &LGen::operator<<(File &file, const Simulation &simulation) {
	if(simulation.getGeneration() > 0) {
		auto fileState = File();

		file.set(KEY_STATE, fileState << simulation.getState());
	}

	auto fileInitial = File();
	auto fileMutator = File();

	file.set(KEY_GENERATION, simulation.getGeneration());
	file.set(KEY_INITIAL, fileInitial << simulation.getInitial());
	file.set(KEY_MUTATOR, fileMutator << simulation.getMutator());
	file.set(KEY_DENSITY, simulation.getDensity());

	return file;
}

std::unique_ptr<Simulation> &LGen::operator<<(std::unique_ptr<Simulation> &simulation, const File &file) {
	std::unique_ptr<State> initial;
	std::unique_ptr<State> state;
	std::unique_ptr<Mutator> mutator;

	const size_t generation = file.getSize(KEY_GENERATION);

	initial << file.getFile(KEY_INITIAL);
	mutator << file.getFile(KEY_MUTATOR);

	if(generation > 0)
		simulation = std::make_unique<Simulation>(
			std::move(mutator),
			std::make_unique<Utility>(), // TODO: Deserialize
			std::move(initial),
			std::move(state << file.getFile(KEY_STATE)),
			generation);
	else
		simulation = std::make_unique<Simulation>(
			std::move(mutator),
			std::make_unique<Utility>(), // TODO: Deserialize
			std::move(initial));

	simulation->setDensity(file.getFloat(KEY_DENSITY));

	return simulation;
}