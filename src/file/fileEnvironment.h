#pragma once

#include "file/file.h"
#include "environment/environment.h"

namespace LGen {
	class FileEnvironment final {
	public:
		static File serialize(const Environment &environment);
		static Environment deserialize(const File &file);

	private:
		static const std::string KEY_MAX_ITERATIONS;
	};
}
