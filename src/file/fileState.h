#pragma once

#include "file/file.h"
#include "simulation/state.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const State &simulation);
	std::unique_ptr<State> &operator<<(std::unique_ptr<State> &state, const File &file);
}