#include "mutator.h"
#include "lrender.h"

#include <vector>

using namespace LGen;

Mutator::Mutator() :
	pSymbolAdd(0.005f),
	pSymbolRemove(0.005f),
	pSymbolChanceNew(0.3f),
	pSymbolChanceRotation(0.2f),
	pSymbolChanceSeed(0.1f),
	pSymbolChanceStep(0.4f),

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

		const auto newRule = LParse::Rule(mutate(rule.getLhs(), randomizer), mutate(rule.getRhs(), randomizer));

		if(!newRule.getLhs().getTokens().empty())
			rules.push_back(newRule);

		if(randomizer.makeFloat() < pRuleDuplicate)
			rules.push_back(rule);
	}

	LParse::System mutated;
	LParse::Sentence newAxiom = mutate(system.getAxiom(), randomizer);

	if(newAxiom.getTokens().empty())
		mutated.setAxiom(system.getAxiom());
	else
		mutated.setAxiom(newAxiom);

	mutated.setRules(rules);

	return mutated;
}

LParse::Sentence Mutator::mutate(const LParse::Sentence& sentence, LParse::Randomizer &randomizer) const {
	std::vector<LParse::Token> tokens;

	for(const auto &token : sentence.getTokens()) {
		switch(token.getSymbol()) {
		case LRender::AgentModel::SYM_LEAF:
		case LRender::AgentModel::SYM_BRANCH_OPEN:
		case LRender::AgentModel::SYM_BRANCH_CLOSE:
			tokens.push_back(token);
			break;
		default:
			if(randomizer.makeFloat() < pSymbolRemove)
				continue;
			
			tokens.push_back(token);
			
			if(randomizer.makeFloat() < pSymbolAdd)
				tokens.push_back(makeToken(randomizer));
				
			break;
		}
	}

	return LParse::Sentence(tokens);
}

LParse::Token Mutator::makeToken(LParse::Randomizer& randomizer) const {
	const auto chance = randomizer.makeFloat();

	if(chance < pSymbolChanceRotation) {
		switch(randomizer.makeInt(0, 3)) {
		case 0:
			return LRender::AgentModel::SYM_PITCH_INCREMENT;
		case 1:
			return LRender::AgentModel::SYM_PITCH_DECREMENT;
		case 2:
			return LRender::AgentModel::SYM_ROLL_INCREMENT;
		default:
			return LRender::AgentModel::SYM_ROLL_DECREMENT;
		}
	}

	if(chance < pSymbolChanceRotation + pSymbolChanceSeed)
		return LRender::AgentModel::SYM_SEED;

	if(chance < pSymbolChanceRotation + pSymbolChanceSeed + pSymbolChanceStep)
		return randomizer.makeInt(LRender::AgentModel::SYM_STEP_MIN, LRender::AgentModel::SYM_STEP_MAX);

	return randomizer.makeInt('a', 'z');
}