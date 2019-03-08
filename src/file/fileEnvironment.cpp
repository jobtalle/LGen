#include "fileEnvironment.h"
#include "fileTerrain.h"

#include "environment/terrain/terrainDropwave.h"

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

File &LGen::operator<<(File& file, const Environment &environment) {
	file = FileEnvironment::serialize(environment);

	return file;
}

const File &LGen::operator>>(const File &file, std::unique_ptr<Environment> &environment) {
	environment = std::make_unique<LGen::Environment>(FileEnvironment::deserialize(file));

	return file;
}