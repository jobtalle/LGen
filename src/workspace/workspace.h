#pragma once

#include "lparse.h"

#include <memory>
#include <random>

namespace LGen {
	class System;

	struct Workspace {
		Workspace();
		std::mt19937 randomizer;
		std::unique_ptr<LParse::System> system;
	};
}