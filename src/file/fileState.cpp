#include "fileState.h"
#include "fileEnvironment.h"
#include "fileRandomizer.h"

using namespace LGen;

static const std::string KEY_ENVIRONMENT = "environment";
static const std::string KEY_RANDOMIZER = "randomizer";
static const std::string KEY_GENERATION = "generation";

File &LGen::operator<<(File &file, const State &state) {
	auto fileEnvironment = File();
	auto fileRandomizer = File();

	fileEnvironment << state.getEnvironment();
	fileRandomizer << state.getRandomizer();

	file.set(KEY_ENVIRONMENT, fileEnvironment);
	file.set(KEY_RANDOMIZER, fileRandomizer);
	file.set(KEY_GENERATION, state.getGeneration());

	return file;
}

std::unique_ptr<State> &LGen::operator<<(std::unique_ptr<State> &state, const File &file) {
	std::unique_ptr<Environment> environment;
	std::unique_ptr<LParse::Randomizer> randomizer;

	environment << file.getFile(KEY_ENVIRONMENT);
	randomizer << file.getFile(KEY_RANDOMIZER);

	state = std::make_unique<State>(std::move(environment), *randomizer, file.getSize(KEY_GENERATION));

	return state;
}