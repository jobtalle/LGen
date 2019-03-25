#pragma once

#include "lparse.h"
#include "../environment/environment.h"

#include <memory>

namespace LGen {
	class Workspace final {
	public:
		Workspace();

		LParse::Randomizer randomizer;
		std::unique_ptr<LParse::System> system;
		std::unique_ptr<Environment> environment;
		size_t systemIterations;

	private:
		static const size_t ITERATIONS_DEFAULT = 5;
	};
}