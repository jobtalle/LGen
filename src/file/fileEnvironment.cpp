#include "fileEnvironment.h"
#include "fileTerrain.h"
#include "file.h"

using namespace LGen;

static const std::string KEY_MAX_ITERATIONS = "max-iterations";
static const std::string KEY_TERRAIN = "terrain";

File &LGen::operator<<(File& file, const std::shared_ptr<Environment> &environment) {
	file.set(KEY_MAX_ITERATIONS, static_cast<int>(environment->getMaxIterations()));
	file.set(KEY_TERRAIN, File() << environment->getTerrain());

	return file;
}

std::shared_ptr<Environment> &LGen::operator<<(std::shared_ptr<Environment> &environment, const File &file) {
	environment = std::make_shared<LGen::Environment>();

	environment->setMaxIterations(file.getInt(KEY_MAX_ITERATIONS));
	environment->setTerrain(std::shared_ptr<Terrain>() << file.getFile(KEY_TERRAIN));

	return environment;
}