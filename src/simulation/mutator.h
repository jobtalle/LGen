#pragma once

#include "lparse.h"

namespace LGen {
	class Mutator final {
	public:
		Mutator();
		LParse::System mutate(const LParse::System &system, LParse::Randomizer &randomizer) const;

	private:
		LParse::Sentence mutate(const LParse::Sentence &sentence) const;

		const float pSymbolAdd;
		const float pSymbolRemove;

		const float pBranchAdd;
		const float pBranchRemove;

		const float pLeafAdd;
		const float pLeafRemove;

		const float pRuleDuplicate;
		const float pRuleAdd;
		const float pRuleRemove;
	};
}