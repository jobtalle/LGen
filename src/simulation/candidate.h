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
			LRender::ReportLimits limits,
			float score);

		float getX() const;
		float getY() const;
		const LParse::System &getSystem() const;

	private:
		const float x;
		const float y;
		const LParse::System system;
		const LRender::ReportLimits limits;
		const float score;
	};
}