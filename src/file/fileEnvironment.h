#pragma once

#include "file/file.h"
#include "environment/environment.h"

namespace LGen {
	namespace File {
		class Environment final : public File {
		public:
			Environment(const std::string &file);
			Environment(const LGen::Environment &environment);
			LGen::Environment getEnvironment() const;

		private:
			static const std::string KEY_MAX_ITERATIONS;
		};
	}
}
