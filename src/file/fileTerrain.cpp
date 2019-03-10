#include "fileTerrain.h"
#include "environment/terrain/terrainDropwave.h"
#include "environment/terrain/terrainFlat.h"

using namespace LGen;

static const std::string KEY_TYPE = "type";
static const std::string KEY_WIDTH = "width";
static const std::string KEY_HEIGHT = "height";

static const std::string KEY_DROPWAVE_PERIOD = "period";

static void serializeDropwave(const TerrainDropwave& terrain, File& file) {
	file.set(KEY_WIDTH, terrain.getWidth());
	file.set(KEY_HEIGHT, terrain.getHeight());
	file.set(KEY_DROPWAVE_PERIOD, terrain.getPeriod());
}

static void serializeFlat(const TerrainFlat &terrain, File &file) {
	file.set(KEY_WIDTH, terrain.getWidth());
	file.set(KEY_HEIGHT, terrain.getHeight());
}

static std::unique_ptr<TerrainDropwave> deserializeDropwave(const File& file) {
	return std::make_unique<TerrainDropwave>(
		file.getFloat(KEY_WIDTH),
		file.getFloat(KEY_HEIGHT),
		file.getFloat(KEY_DROPWAVE_PERIOD));
}

static std::unique_ptr<TerrainFlat> deserializeFlat(const File &file) {
	return std::make_unique<TerrainFlat>(
		file.getFloat(KEY_WIDTH),
		file.getFloat(KEY_HEIGHT));
}

File &LGen::operator<<(File &file, const Terrain &terrain) {
	file.set(KEY_TYPE, terrain.getType());

	if(terrain.getType() == TerrainDropwave::TYPE)
		serializeDropwave(static_cast<const TerrainDropwave&>(terrain), file);
	else if(terrain.getType() == TerrainFlat::TYPE)
		serializeFlat(static_cast<const TerrainFlat&>(terrain), file);

	return file;
}

std::unique_ptr<Terrain> &LGen::operator<<(std::unique_ptr<Terrain> &terrain, const File &file) {
	const auto type = file.getString(KEY_TYPE);

	if(type == TerrainDropwave::TYPE)
		terrain = deserializeDropwave(file);
	else if(type == TerrainFlat::TYPE)
		terrain = deserializeFlat(file);
	else
		terrain = nullptr;

	return terrain;
}