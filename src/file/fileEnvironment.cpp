#include "fileEnvironment.h"
#include "fileTerrain.h"
#include "file.h"

using namespace LGen;

static const std::string KEY_MAX_ITERATIONS = "max-iterations";
static const std::string KEY_TERRAIN = "terrain";

File &LGen::operator<<(File& file, const Environment &environment) {
	auto fileTerrain = File();
	
	fileTerrain << *environment.getTerrain();

	file.set(KEY_MAX_ITERATIONS, static_cast<int>(environment.getMaxIterations()));
	file.set(KEY_TERRAIN, fileTerrain);

	return file;
}

std::unique_ptr<Environment> &LGen::operator<<(std::unique_ptr<Environment> &environment, const File &file) {
	environment = std::make_unique<LGen::Environment>();
	
	std::unique_ptr<Terrain> terrain;

	environment->setMaxIterations(file.getInt(KEY_MAX_ITERATIONS));
	environment->setTerrain(std::move(terrain << file.getFile(KEY_TERRAIN)));

	return environment;
}
