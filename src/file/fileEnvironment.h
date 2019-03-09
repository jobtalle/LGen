#pragma once

#include "file/file.h"
#include "environment/environment.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const Environment &environment);
	std::unique_ptr<Environment> &operator<<(std::unique_ptr<Environment> &environment, const File &file);
}
