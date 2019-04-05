#include "mutator.h"

#include <vector>

using namespace LGen;

Mutator::Mutator() :
	pSymbolAdd(0.005f),
	pSymbolRemove(0.005f),
	pBranchAdd(0.002f),
	pBranchRemove(0.002f),
	pLeafAdd(0.002f),
	pLeafRemove(0.002f),
	pRuleDuplicate(0.003f),
	pRuleAdd(0.001f),
	pRuleRemove(0.004f) {
	
}

LParse::System Mutator::mutate(const LParse::System& system, LParse::Randomizer &randomizer) const {
	std::vector<LParse::Rule> rules;;

	for(const auto &rule : system.getRules()) {
		if(randomizer.makeFloat() < pRuleRemove)
			continue;

		rules.emplace_back(mutate(rule.getLhs()), mutate(rule.getRhs()));

		if(randomizer.makeFloat() < pRuleDuplicate)
			rules.push_back(rule);
	}

	LParse::System mutated;
	
	mutated.setAxiom(mutate(system.getAxiom()));
	mutated.setRules(rules);

	return mutated;
}

LParse::Sentence Mutator::mutate(const LParse::Sentence& sentence) const {
	LParse::Sentence newSentence;



	return sentence;
}
