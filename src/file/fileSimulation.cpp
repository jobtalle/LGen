#include "fileSimulation.h"
#include "fileEnvironment.h"
#include "fileRandomizer.h"

using namespace LGen;

static const std::string KEY_ENVIRONMENT = "environment";
static const std::string KEY_RANDOMIZER = "randomizer";

File &LGen::operator<<(File &file, const Simulation &simulation) {
	auto fileEnvironment = File();
	auto fileRandomizer = File();

	fileEnvironment << simulation.getEnvironment();
	fileRandomizer << simulation.getRandomizer();

	file.set(KEY_ENVIRONMENT, fileEnvironment);
	file.set(KEY_RANDOMIZER, fileRandomizer);

	return file;
}

std::unique_ptr<Simulation> &LGen::operator<<(std::unique_ptr<Simulation> &simulation, const File &file) {
	std::unique_ptr<LParse::Randomizer> randomizer;

	randomizer << file.getFile(KEY_RANDOMIZER);

	simulation = std::make_unique<Simulation>(*randomizer);

	std::unique_ptr<Environment> environment;

	simulation->setEnvironment(std::move(environment << file.getFile(KEY_ENVIRONMENT)));

	return simulation;
}