#pragma once

#include "lparse.h"

namespace LGen {
	class Mutator final {
	public:
		LParse::System mutate(const LParse::System &system) const;
	};
}