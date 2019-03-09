#include "fileTerrain.h"

using namespace LGen;

static const std::string KEY_TYPE = "type";
static const std::string KEY_WIDTH = "width";
static const std::string KEY_HEIGHT = "height";

static const std::string KEY_DROPWAVE_PERIOD = "period";

void serializeDropwave(const TerrainDropwave& terrain, File& file) {
	file.set(KEY_WIDTH, terrain.getWidth());
	file.set(KEY_HEIGHT, terrain.getHeight());
	file.set(KEY_DROPWAVE_PERIOD, terrain.getPeriod());
}


static std::shared_ptr<TerrainDropwave> deserializeDropwave(const File& file) {
	std::shared_ptr<TerrainDropwave> terrain = std::make_shared<TerrainDropwave>(
		file.getFloat(KEY_WIDTH),
		file.getFloat(KEY_HEIGHT),
		file.getFloat(KEY_DROPWAVE_PERIOD));

	return terrain;
}

File &LGen::operator<<(File &file, const std::shared_ptr<Terrain> &terrain) {
	file.set(KEY_TYPE, terrain->getType());

	if(terrain->getType() == TerrainDropwave::TYPE)
		serializeDropwave(*std::dynamic_pointer_cast<TerrainDropwave>(terrain), file);

	return file;
}

std::shared_ptr<Terrain> &LGen::operator<<(std::shared_ptr<Terrain> &terrain, const File &file) {
	const auto type = file.getString(KEY_TYPE);

	if(type == TerrainDropwave::TYPE)
		terrain = deserializeDropwave(file);
	else
		terrain = nullptr;

	return terrain;
}