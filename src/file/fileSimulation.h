#pragma once

#include "file/file.h"
#include "simulation/simulation.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const Simulation &simulation);
	std::unique_ptr<Simulation> &operator<<(std::unique_ptr<Simulation> &simulation, const File &file);
}