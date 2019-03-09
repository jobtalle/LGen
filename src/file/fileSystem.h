#pragma once

#include "file/file.h"
#include "lparse.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const std::shared_ptr<LParse::System> &system);
	std::shared_ptr<LParse::System> &operator<<(std::shared_ptr<LParse::System> &system, const File &file);
}
