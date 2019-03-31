#include "fileSimulation.h"
#include "fileState.h"

using namespace LGen;

static const std::string KEY_INITIAL = "initial";
static const std::string KEY_STATE = "state";
static const std::string KEY_GENERATION = "generation";

File &LGen::operator<<(File &file, const Simulation &simulation) {
	if(simulation.getState().getGeneration() > 0) {
		auto fileState = File();

		file.set(KEY_STATE, fileState << simulation.getState());
	}

	auto fileInitial = File();

	file.set(KEY_GENERATION, simulation.getState().getGeneration());
	file.set(KEY_INITIAL, fileInitial << simulation.getInitial());

	return file;
}

std::unique_ptr<Simulation> &LGen::operator<<(std::unique_ptr<Simulation> &simulation, const File &file) {
	std::unique_ptr<State> initial;
	std::unique_ptr<State> state;

	const size_t generation = file.getSize(KEY_GENERATION);

	initial << file.getFile(KEY_INITIAL);

	if(generation > 0)
		simulation = std::make_unique<Simulation>(
			std::move(initial),
			std::move(state << file.getFile(KEY_STATE)));
	else
		simulation = std::make_unique<Simulation>(std::move(initial));

	return simulation;
}