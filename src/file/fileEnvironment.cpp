#include "fileEnvironment.h"
#include "fileTerrain.h"

#include "environment/terrain/terrainDropwave.h"

#include <sstream>

using namespace LGen;

const std::string FileEnvironment::KEY_MAX_ITERATIONS = "max-iterations";
const std::string FileEnvironment::KEY_TERRAIN = "terrain";

File FileEnvironment::serialize(const Environment &environment) {
	File file;

	file.set(KEY_MAX_ITERATIONS, static_cast<int>(environment.getMaxIterations()));

	if(environment.getTerrain()->getType() == TerrainDropwave::TYPE)
		file.set(KEY_TERRAIN, FileTerrain::serialize(*std::dynamic_pointer_cast<TerrainDropwave>(environment.getTerrain())));

	return file;
}

Environment FileEnvironment::deserialize(const File &file) {
	Environment environment;

	environment.setMaxIterations(file.getInt(KEY_MAX_ITERATIONS));
	environment.setTerrain(FileTerrain::deserialize(file.getFile(KEY_TERRAIN)));

	return environment;
}