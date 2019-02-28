#pragma once

#include "lparse.h"

#include <string>
#include <random>
#include <memory>

namespace LGen {
	class Agent final {
	public:
		Agent(const LParse::System &system);
		std::shared_ptr<LParse::Sentence> generate(const size_t steps, std::mt19937 &randomizer) const;

	private:
		LParse::System system;
	};
};