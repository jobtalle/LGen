#pragma once

#include "file/file.h"
#include "environment/terrain/terrainDropwave.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const std::shared_ptr<Terrain> &terrain);
	std::shared_ptr<Terrain> &operator<<(std::shared_ptr<Terrain> &terrain, const File &file);
}