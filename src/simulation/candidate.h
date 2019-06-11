#pragma once

#include "lrender.h"
#include "lparse.h"

namespace LGen {
	class Candidate final {
	public:
		Candidate(
			float x,
			float y,
			const LParse::System &system,
			const LRender::ReportLimits &limits,
			double score);
		Candidate &operator=(const Candidate &other) = default;

		float getX() const;
		float getY() const;
		const LParse::System &getSystem() const;
		float getRadius() const;
		double getScore() const;
		static bool compare(const Candidate &a, const Candidate &b);

	private:
		static const float RADIUS_OFFSET;

		float x;
		float y;
		LParse::System system;
		float radius;
		double score;
	};
}