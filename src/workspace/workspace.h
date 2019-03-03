#pragma once

#include "lparse.h"

#include <memory>
#include <random>

namespace LGen {
	struct Workspace {
	public:
		Workspace();
		std::mt19937 randomizer;
		std::unique_ptr<LParse::System> system;
		size_t systemIterations;

	private:
		static const size_t ITERATIONS_DEFAULT = 4;
	};
}