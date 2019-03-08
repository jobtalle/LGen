#pragma once

#include "file/file.h"
#include "environment/terrain/terrainDropwave.h"

#include <memory>

namespace LGen {
	class FileTerrain final {
	public:
		static File serialize(const TerrainDropwave &terrain);
		static std::shared_ptr<Terrain> deserialize(const File &file);

	private:
		static const std::string KEY_TYPE;
		static const std::string KEY_WIDTH;
		static const std::string KEY_HEIGHT;

		static const std::string TYPE_DROPWAVE;
		static const std::string KEY_DROPWAVE_PERIOD;

		static void serializeDropwave(const TerrainDropwave &terrain, File &file);
		static std::shared_ptr<TerrainDropwave> deserializeDropwave(const File &file);
	};
}