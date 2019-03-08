#include "fileTerrain.h"

using namespace LGen;

const std::string FileTerrain::KEY_TYPE = "type";
const std::string FileTerrain::KEY_WIDTH = "width";
const std::string FileTerrain::KEY_HEIGHT = "height";

const std::string FileTerrain::KEY_DROPWAVE_PERIOD = "period";

File FileTerrain::serialize(const TerrainDropwave& terrain) {
	File file;

	file.set(KEY_TYPE, TerrainDropwave::TYPE);

	serializeDropwave(terrain, file);

	return file;
}

std::shared_ptr<Terrain> FileTerrain::deserialize(const File& file) {
	std::string type = file.getString(KEY_TYPE);

	if(type == TerrainDropwave::TYPE)
		return deserializeDropwave(file);

	return nullptr;
}

void FileTerrain::serializeDropwave(const TerrainDropwave& terrain, File& file) {
	file.set(KEY_WIDTH, terrain.getWidth());
	file.set(KEY_HEIGHT, terrain.getHeight());
	file.set(KEY_DROPWAVE_PERIOD, terrain.getPeriod());
}


std::shared_ptr<TerrainDropwave> FileTerrain::deserializeDropwave(const File& file) {
	std::shared_ptr<TerrainDropwave> terrain = std::make_shared<TerrainDropwave>(
		file.getFloat(KEY_WIDTH),
		file.getFloat(KEY_HEIGHT),
		file.getFloat(KEY_DROPWAVE_PERIOD));

	return terrain;
}
