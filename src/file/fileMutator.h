#pragma once

#include "file/file.h"
#include "simulation/mutator.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const Mutator &mutator);
	std::unique_ptr<Mutator> &operator<<(std::unique_ptr<Mutator> &mutator, const File &file);
}