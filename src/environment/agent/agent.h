#pragma once

#include "lparse.h"

#include <string>
#include <random>
#include <memory>

namespace LGen {
	class Agent final {
	public:
		Agent(const LParse::System &system, const float x, const float y);
		std::shared_ptr<LParse::Sentence> generate(const size_t steps, std::mt19937 &randomizer) const;
		const float getX() const;
		const float getY() const;

	private:
		const LParse::System system;
		const float x;
		const float y;
	};
}