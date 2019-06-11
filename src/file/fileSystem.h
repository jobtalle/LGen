#pragma once

#include "file/file.h"
#include "lparse.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const LParse::System &system);
	std::unique_ptr<LParse::System> &operator<<(std::unique_ptr<LParse::System> &system, const File &file);
}
