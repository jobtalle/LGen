#pragma once

#include "file/file.h"
#include "environment/terrain/terrainDropwave.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const Terrain &terrain);
	std::unique_ptr<Terrain> &operator<<(std::unique_ptr<Terrain> &terrain, const File &file);
}