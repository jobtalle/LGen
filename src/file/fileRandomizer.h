#pragma once

#include "file/file.h"
#include "lparse.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const LParse::Randomizer &randomizer);
	std::unique_ptr<LParse::Randomizer> &operator<<(std::unique_ptr<LParse::Randomizer> &randomizer, const File &file);
}