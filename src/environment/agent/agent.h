#pragma once

#include "lparse.h"

namespace LGen {
	class Agent final {
	public:
		Agent(const LParse::System &system);

	private:
		LParse::System system;
	};
};