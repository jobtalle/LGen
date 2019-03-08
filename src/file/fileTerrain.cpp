#include "fileTerrain.h"

using namespace LGen;

const std::string FileTerrain::KEY_TYPE = "type";
const std::string FileTerrain::KEY_WIDTH = "width";
const std::string FileTerrain::KEY_HEIGHT = "height";

const std::string FileTerrain::TYPE_DROPWAVE = "dropwave";
const std::string FileTerrain::KEY_DROPWAVE_PERIOD = "period";

File FileTerrain::serialize(const TerrainDropwave& terrain) {
	File file;

	file.set(KEY_TYPE, TYPE_DROPWAVE);

	serializeDropwave(terrain, file);

	return file;
}

std::shared_ptr<Terrain> FileTerrain::deserialize(const File& file) {
	std::string type;
	
	file.get(KEY_TYPE, type);

	if(type == TYPE_DROPWAVE)
		return deserializeDropwave(file);

	return nullptr;
}

void FileTerrain::serializeDropwave(const TerrainDropwave& terrain, File& file) {
	file.set(KEY_WIDTH, std::to_string(terrain.getWidth()));
	file.set(KEY_HEIGHT, std::to_string(terrain.getHeight()));
	file.set(KEY_DROPWAVE_PERIOD, std::to_string(terrain.getPeriod()));
}


std::shared_ptr<TerrainDropwave> FileTerrain::deserializeDropwave(const File& file) {
	std::string width;
	std::string height;
	std::string period;

	file.get(KEY_WIDTH, width);
	file.get(KEY_HEIGHT, height);
	file.get(KEY_DROPWAVE_PERIOD, period);

	std::shared_ptr<TerrainDropwave> terrain = std::make_shared<TerrainDropwave>(
		std::stof(width),
		std::stof(height),
		std::stof(period));

	return terrain;
}
