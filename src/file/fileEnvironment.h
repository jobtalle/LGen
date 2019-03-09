#pragma once

#include "file/file.h"
#include "environment/environment.h"

#include <memory>

namespace LGen {
	File &operator<<(File &file, const std::shared_ptr<Environment> &environment);
	std::shared_ptr<Environment> &operator<<(std::shared_ptr<Environment> &environment, const File &file);
}
