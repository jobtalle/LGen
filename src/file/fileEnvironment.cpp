#include "fileEnvironment.h"
#include "fileTerrain.h"

#include "environment/terrain/terrainDropwave.h"

#include <sstream>

using namespace LGen;

const std::string FileEnvironment::KEY_MAX_ITERATIONS = "max-iterations";
const std::string FileEnvironment::KEY_TERRAIN = "terrain";

File FileEnvironment::serialize(const Environment &environment) {
	File file;

	file.set(KEY_MAX_ITERATIONS, std::to_string(environment.getMaxIterations()));
	file.set(KEY_TERRAIN, FileTerrain::serialize(*std::dynamic_pointer_cast<TerrainDropwave>(environment.getTerrain())));

	return file;
}

Environment FileEnvironment::deserialize(const File &file) {
	Environment environment;

	std::string maxIterations;
	File terrainFile;

	file.get(KEY_MAX_ITERATIONS, maxIterations);
	file.get(KEY_TERRAIN, terrainFile);

	environment.setMaxIterations(std::stoi(maxIterations));
	environment.setTerrain(FileTerrain::deserialize(terrainFile));

	return environment;
}