#pragma once

#include "file/fileConfig.h"
#include "environment/environment.h"

namespace LGen {
	namespace File {
		class Environment final : public Config {
		public:
			Environment(const std::string &file);
			Environment(const LGen::Environment &environment);
			LGen::Environment getEnvironment() const;

		private:
			static const std::string KEY_MAX_ITERATIONS;
		};
	}
}