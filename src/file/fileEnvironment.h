#pragma once

#include "file/file.h"
#include "environment/environment.h"
#include "lparse.h"

namespace LGen {
	class FileEnvironment final {
	public:
		static File serialize(const Environment &environment);
		static Environment deserialize(const File &file);

	private:
		static const std::string KEY_MAX_ITERATIONS;
		static const std::string KEY_TERRAIN;
	};

	File &operator<<(File &file, const Environment &environment);
	const File &operator>>(const File &file, std::unique_ptr<Environment> &environment);
}
