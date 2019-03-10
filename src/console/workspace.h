#pragma once

#include "lparse.h"
#include "../environment/environment.h"

#include <random>
#include <memory>

namespace LGen {
	class Workspace final {
	public:
		Workspace();

		std::mt19937 randomizer;
		std::unique_ptr<LParse::System> system;
		std::unique_ptr<LGen::Environment> environment;
		size_t systemIterations;

	private:
		static const size_t ITERATIONS_DEFAULT = 5;
	};
}