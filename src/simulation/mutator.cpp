#include "mutator.h"
#include "lrender.h"

#include <vector>

using namespace LGen;

Mutator::GeneratedSymbols::GeneratedSymbols(
	const std::vector<LParse::Token>& generatedTokens,
	const float pStep,
	const float pConstant,
	const float pRotation,
	const float pSeed) :
	pStep(pStep),
	pConstant(pConstant),
	pRotation(pRotation),
	pSeed(pSeed) {
	for(const auto &token : generatedTokens) {
		switch(token.getSymbol()) {
		case LParse::Legend::BRANCH_OPEN:
		case LParse::Legend::BRANCH_CLOSE:
		case LParse::Legend::LEAF:
			continue;
		case LParse::Legend::PITCH_INCREMENT:
		case LParse::Legend::PITCH_DECREMENT:
		case LParse::Legend::ROLL_INCREMENT:
		case LParse::Legend::ROLL_DECREMENT:
			rotations.push_back(token);

			break;
		case LParse::Legend::SEED:
			seeds.push_back(token);

			break;
		default:
			if(token.getSymbol() >= LParse::Legend::STEP_MIN && token.getSymbol() <= LParse::Legend::STEP_MAX)
				steps.push_back(token);
			else
				constants.push_back(token);

			break;
		}
	}

	if(empty())
		return;
	
	if(rotations.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pRotation);

		this->pSeed *= multiplier;
		this->pStep *= multiplier;
		this->pConstant *= multiplier;
		this->pRotation = 0;
	}

	if(seeds.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pSeed);

		this->pRotation *= multiplier;
		this->pStep *= multiplier;
		this->pConstant *= multiplier;
		this->pSeed = 0;
	}

	if(steps.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pStep);

		this->pRotation *= multiplier;
		this->pSeed *= multiplier;
		this->pConstant *= multiplier;
		this->pStep = 0;
	}

	if(constants.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pConstant);

		this->pRotation *= multiplier;
		this->pSeed *= multiplier;
		this->pStep *= multiplier;
		this->pConstant = 0;
	}

	normalize();
}

const std::vector<LParse::Token>& Mutator::GeneratedSymbols::getSteps() const {
	return steps;
}

const std::vector<LParse::Token>& Mutator::GeneratedSymbols::getConstants() const {
	return constants;
}

const std::vector<LParse::Token>& Mutator::GeneratedSymbols::getRotations() const {
	return rotations;
}

const std::vector<LParse::Token>& Mutator::GeneratedSymbols::getSeeds() const {
	return seeds;
}

float Mutator::GeneratedSymbols::getPStep() const {
	return pStep;
}

float Mutator::GeneratedSymbols::getPConstant() const {
	return pConstant;
}

float Mutator::GeneratedSymbols::getPRotation() const {
	return pRotation;
}

float Mutator::GeneratedSymbols::getPSeed() const {
	return pSeed;
}

bool Mutator::GeneratedSymbols::empty() const {
	return steps.empty() && constants.empty() && rotations.empty() && seeds.empty();
}

void Mutator::GeneratedSymbols::normalize() {
	const auto remainder = 1.0f - pStep - pConstant - pRotation - pSeed;

	if(pStep != 0)
		pStep += remainder;
	else if(pConstant != 0)
		pConstant += remainder;
	else if(pRotation != 0)
		pRotation += remainder;
	else
		pSeed += remainder;
}

Mutator::Mutator() :
	pSymbolAdd(0.005f),
	pSymbolRemove(0.005f),
	pSymbolChanceNew(0.2f),
	pSymbolChanceRotation(0.35f),
	pSymbolChanceSeed(0.05f),
	pSymbolChanceStep(0.4f),
	pSymbolChanceConstant(0.3f),

	pBranchAdd(0.002f),
	pBranchRemove(0.002f),

	pLeafAdd(0.002f),
	pLeafRemove(0.002f),

	pRuleDuplicate(0.003f),
	pRuleAdd(0.001f),
	pRuleRemove(0.004f) {

}

LParse::System Mutator::mutate(const LParse::System& system, LParse::Randomizer &randomizer) const {
	std::vector<LParse::Rule> rules;
	const GeneratedSymbols generated(
		system.getGeneratedTokens(),
		pSymbolChanceStep,
		pSymbolChanceConstant,
		pSymbolChanceRotation,
		pSymbolChanceSeed);

	for(const auto &rule : system.getRules()) {
		if(randomizer.makeFloat() < pRuleRemove)
			continue;

		const auto newRule = LParse::Rule(
			mutate(rule.getLhs(), randomizer, false, &generated), 
			mutate(rule.getRhs(), randomizer, true, &generated));

		if(!newRule.getLhs().getTokens().empty())
			rules.push_back(newRule);

		if(randomizer.makeFloat() < pRuleDuplicate)
			rules.push_back(rule);
	}

	if(randomizer.makeFloat() < pRuleAdd) {
		if(randomizer.makeFloat() < pSymbolChanceNew)
			rules.emplace_back(
				makeToken(randomizer, &generated),
				makeToken(randomizer));
		else
			rules.emplace_back(
				makeToken(randomizer, &generated),
				makeToken(randomizer, &generated));
	}

	LParse::System mutated;
	LParse::Sentence newAxiom = mutate(system.getAxiom(), randomizer, true, &generated);

	if(newAxiom.getTokens().empty())
		mutated.setAxiom(system.getAxiom());
	else
		mutated.setAxiom(newAxiom);

	mutated.setRules(rules);

	return mutated;
}

LParse::Sentence Mutator::mutate(
	const LParse::Sentence& sentence,
	LParse::Randomizer &randomizer,
	const bool allowNew,
	const GeneratedSymbols *generated) const {
	std::vector<LParse::Token> tokens;
	size_t scope = 0;

	for(const auto &token : sentence.getTokens()) {
		switch(token.getSymbol()) {
		case LParse::Legend::LEAF:
			if(randomizer.makeFloat() < pLeafRemove)
				break;

			tokens.push_back(token);
			++scope;

			break;
		case LParse::Legend::BRANCH_OPEN:
			if(randomizer.makeFloat() < pBranchRemove)
				break;

			tokens.push_back(token);
			++scope;

			break;
		case LParse::Legend::BRANCH_CLOSE:
			if(scope > 0) {
				tokens.push_back(token);
				--scope;
			}

			break;
		default:
			if(randomizer.makeFloat() < pSymbolRemove)
				continue;

			const auto makeBranch = randomizer.makeFloat() < pBranchAdd;
			const auto makeLeaf = !makeBranch && randomizer.makeFloat() < pLeafAdd;
			const auto addSymbol = randomizer.makeFloat() < pSymbolAdd;
			const auto addSymbolPre = addSymbol ? randomizer.makeFloat(0, 1) < 0.5f : false;
			
			if(makeBranch)
				tokens.emplace_back(LParse::Legend::BRANCH_OPEN);
			else if(makeLeaf)
				tokens.emplace_back(LParse::Legend::LEAF);

			if(!addSymbolPre)
				tokens.push_back(token);
			
			if(randomizer.makeFloat() < pSymbolAdd) {
				if(allowNew && randomizer.makeFloat() < pSymbolChanceNew)
					tokens.push_back(makeToken(randomizer));
				else
					tokens.push_back(makeToken(randomizer, generated));
			}

			if(addSymbolPre)
				tokens.push_back(token);

			if(makeBranch || makeLeaf)
				tokens.emplace_back(LParse::Legend::BRANCH_CLOSE);
				
			break;
		}

		if(tokens.size() >= SENTENCE_LENGTH_LIMIT)
			break;
	}

	while(scope > 0)
		--scope, tokens.emplace_back(LParse::Legend::BRANCH_CLOSE);

	return LParse::Sentence(tokens);
}

LParse::Token Mutator::makeToken(LParse::Randomizer& randomizer) const {
	const auto chance = randomizer.makeFloat();

	if(chance <= pSymbolChanceRotation) {
		switch(randomizer.makeInt(0, 5)) {
		case 0:
			return LParse::Legend::PITCH_INCREMENT;
		case 1:
			return LParse::Legend::PITCH_DECREMENT;
		case 2:
			return LParse::Legend::ROLL_INCREMENT;
		case 3:
			return LParse::Legend::ROLL_DECREMENT;
		case 4:
			return LParse::Legend::YAW_INCREMENT;
		default:
			return LParse::Legend::YAW_DECREMENT;
		}
	}

	if(chance <= pSymbolChanceRotation + pSymbolChanceSeed)
		return LParse::Legend::SEED;

	if(chance <= pSymbolChanceRotation + pSymbolChanceSeed + pSymbolChanceStep)
		return randomizer.makeInt(LParse::Legend::STEP_MIN, LParse::Legend::STEP_MAX);

	return randomizer.makeInt(LParse::Legend::CONST_MIN, LParse::Legend::CONST_MAX);
}

LParse::Token Mutator::makeToken(LParse::Randomizer& randomizer, const GeneratedSymbols *constraints) const {
	if(!constraints || constraints->empty())
		return makeToken(randomizer);

	const auto chance = randomizer.makeFloat();

	if(chance <= constraints->getPRotation())
		return constraints->getRotations()[randomizer.makeInt(0, constraints->getRotations().size() - 1)];

	if(chance <= constraints->getPSeed() + constraints->getPRotation())
		return constraints->getSeeds()[randomizer.makeInt(0, constraints->getSeeds().size() - 1)];

	if(chance <= constraints->getPStep() + constraints->getPSeed() + constraints->getPRotation())
		return constraints->getSteps()[randomizer.makeInt(0, constraints->getSteps().size() - 1)];

	return constraints->getConstants()[randomizer.makeInt(0, constraints->getConstants().size() - 1)];
}