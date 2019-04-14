#pragma once

#include "lparse.h"

#include <string>
#include <memory>

namespace LGen {
	class Terrain {
	public:
		Terrain(std::string type, float width, float height);
		virtual ~Terrain() = default;
		const std::string &getType() const;
		float getWidth() const;
		float getHeight() const;
		float get(float x, float y) const;
		const LParse::GrowthProfile &getGrowthProfile(float x, float y) const;

	protected:
		virtual float sample(float x, float y) const = 0;

	private:
		static const size_t GROWTH_PROFILE_RESOLUTION = 10;

		std::unique_ptr<const LParse::GrowthProfile> growthProfiles[GROWTH_PROFILE_RESOLUTION];
		const std::string type;
		const float width;
		const float height;
	};
}