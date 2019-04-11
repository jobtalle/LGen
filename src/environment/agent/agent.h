#pragma once

#include "lparse.h"

#include <memory>

namespace LGen {
	class Agent final {
	public:
		Agent(const LParse::System &system, float x, float y);
		std::shared_ptr<LParse::Sentence> generate(const LParse::GrowthProfile &profile, LParse::Randomizer &randomizer) const;
		const LParse::System &getSystem() const;
		float getX() const;
		float getY() const;

	private:
		const LParse::System system;
		const float x;
		const float y;
	};
}