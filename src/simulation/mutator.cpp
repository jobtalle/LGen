#include "mutator.h"
#include "lrender.h"

#include <vector>

using namespace LGen;

const std::string Mutator::MSG_INTRO = "Mutator probabilities:";
const std::string Mutator::MSG_PROPERTY_INDENTATION = "- ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_ADD = MSG_PROPERTY_INDENTATION + "Symbol addition chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_REMOVE = MSG_PROPERTY_INDENTATION + "Symbol removal chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_NEW = MSG_PROPERTY_INDENTATION + "New symbol introduction chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_ROTATION = MSG_PROPERTY_INDENTATION + "Rotation symbol chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_SEED = MSG_PROPERTY_INDENTATION + "Seed symbol chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_STEP = MSG_PROPERTY_INDENTATION + "Step symbol chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_CONSTANT = MSG_PROPERTY_INDENTATION + "Constant symbol chance: ";
const std::string Mutator::MSG_PREFIX_P_SYMBOL_CHANCE_LEAF = MSG_PROPERTY_INDENTATION + "Leaf symbol chance: ";
const std::string Mutator::MSG_PREFIX_P_BRANCH_ADD = MSG_PROPERTY_INDENTATION + "Branch creation chance: ";
const std::string Mutator::MSG_PREFIX_P_BRANCH_REMOVE = MSG_PROPERTY_INDENTATION + "Branch removal chance: ";
const std::string Mutator::MSG_PREFIX_P_LEAF_ADD = MSG_PROPERTY_INDENTATION + "Leaf creation chance: ";
const std::string Mutator::MSG_PREFIX_P_LEAF_REMOVE = MSG_PROPERTY_INDENTATION + "Leaf removal chance: ";
const std::string Mutator::MSG_PREFIX_P_RULE_DUPLICATE = MSG_PROPERTY_INDENTATION + "Rule duplication chance: ";
const std::string Mutator::MSG_PREFIX_P_RULE_ADD = MSG_PROPERTY_INDENTATION + "Rule creation chance: ";
const std::string Mutator::MSG_PREFIX_P_RULE_REMOVE = MSG_PROPERTY_INDENTATION + "Rule removal chance: ";

Mutator::GeneratedSymbols::GeneratedSymbols(
	const std::vector<LParse::Token>& generatedTokens,
	const float pStep,
	const float pConstant,
	const float pRotation,
	const float pSeed,
	const float pLeaf) :
	pStep(pStep),
	pConstant(pConstant),
	pRotation(pRotation),
	pSeed(pSeed),
	pLeaf(pLeaf) {
	for(const auto &token : generatedTokens) {
		switch(token.getSymbol()) {
		case LParse::Legend::BRANCH_OPEN:
		case LParse::Legend::BRANCH_CLOSE:
		case LParse::Legend::LEAF_OPEN:
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
		case LParse::Legend::LEAF_A:
			leaves.push_back(token);

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

	normalize();
}

const std::vector<LParse::Token> &Mutator::GeneratedSymbols::getSteps() const {
	return steps;
}

const std::vector<LParse::Token> &Mutator::GeneratedSymbols::getConstants() const {
	return constants;
}

const std::vector<LParse::Token> &Mutator::GeneratedSymbols::getRotations() const {
	return rotations;
}

const std::vector<LParse::Token> &Mutator::GeneratedSymbols::getSeeds() const {
	return seeds;
}

const std::vector<LParse::Token> &Mutator::GeneratedSymbols::getLeaves() const {
	return leaves;
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

float Mutator::GeneratedSymbols::getPLeaf() const {
	return pLeaf;
}

bool Mutator::GeneratedSymbols::empty() const {
	return steps.empty() && constants.empty() && rotations.empty() && seeds.empty();
}

void Mutator::GeneratedSymbols::normalize() {
	if(rotations.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pRotation);

		this->pSeed *= multiplier;
		this->pStep *= multiplier;
		this->pConstant *= multiplier;
		this->pLeaf *= multiplier;
		this->pRotation = 0;
	}

	if(seeds.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pSeed);

		this->pRotation *= multiplier;
		this->pStep *= multiplier;
		this->pConstant *= multiplier;
		this->pLeaf *= multiplier;
		this->pSeed = 0;
	}

	if(steps.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pStep);

		this->pRotation *= multiplier;
		this->pSeed *= multiplier;
		this->pConstant *= multiplier;
		this->pLeaf *= multiplier;
		this->pStep = 0;
	}

	if(constants.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pConstant);

		this->pRotation *= multiplier;
		this->pSeed *= multiplier;
		this->pStep *= multiplier;
		this->pLeaf *= multiplier;
		this->pConstant = 0;
	}

	if(leaves.empty()) {
		const auto multiplier = 1.0f / (1.0f - this->pLeaf);

		this->pRotation *= multiplier;
		this->pSeed *= multiplier;
		this->pConstant *= multiplier;
		this->pStep *= multiplier;
		this->pLeaf = 0;
	}

	const auto remainder = 1.0f - pStep - pConstant - pRotation - pSeed - pLeaf;

	if(pStep != 0)
		pStep += remainder;
	else if(pConstant != 0)
		pConstant += remainder;
	else if(pRotation != 0)
		pRotation += remainder;
	else if(pLeaf != 0)
		pLeaf += remainder;
	else
		pSeed += remainder;
}

Mutator::Mutator(
	const float pSymbolAdd,
	const float pSymbolRemove,
	const float pSymbolChanceNew,
	const float pSymbolChanceRotation,
	const float pSymbolChanceSeed,
	const float pSymbolChanceStep,
	const float pSymbolChanceConstant,
	const float pSymbolChanceLeaf,
	const float pBranchAdd,
	const float pBranchRemove,
	const float pLeafAdd,
	const float pLeafRemove,
	const float pRuleDuplicate,
	const float pRuleAdd,
	const float pRuleRemove) :
	pSymbolAdd(pSymbolAdd),
	pSymbolRemove(pSymbolRemove),
	pSymbolChanceNew(pSymbolChanceNew),
	pSymbolChanceRotation(pSymbolChanceRotation),
	pSymbolChanceSeed(pSymbolChanceSeed),
	pSymbolChanceStep(pSymbolChanceStep),
	pSymbolChanceConstant(pSymbolChanceConstant),
	pSymbolChanceLeaf(pSymbolChanceLeaf),
	pBranchAdd(pBranchAdd),
	pBranchRemove(pBranchRemove),
	pLeafAdd(pLeafAdd),
	pLeafRemove(pLeafRemove),
	pRuleDuplicate(pRuleDuplicate),
	pRuleAdd(pRuleAdd),
	pRuleRemove(pRuleRemove) {
	const auto symbolChanceTotal =
		pSymbolChanceRotation +
		pSymbolChanceSeed +
		pSymbolChanceStep +
		pSymbolChanceConstant +
		pSymbolChanceLeaf;

	const auto symbolChanceNormalizer = 1.0f / symbolChanceTotal;

	this->pSymbolChanceRotation *= symbolChanceNormalizer;
	this->pSymbolChanceSeed *= symbolChanceNormalizer;
	this->pSymbolChanceStep *= symbolChanceNormalizer;
	this->pSymbolChanceConstant *= symbolChanceNormalizer;
	this->pSymbolChanceLeaf *= symbolChanceNormalizer;
}

LParse::System Mutator::mutate(const LParse::System& system, LParse::Randomizer &randomizer) const {
	std::vector<LParse::Rule> rules;
	const GeneratedSymbols generated(
		system.getGeneratedTokens(),
		pSymbolChanceStep,
		pSymbolChanceConstant,
		pSymbolChanceRotation,
		pSymbolChanceSeed,
		pSymbolChanceLeaf);

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

void Mutator::print(std::ostream &stream) const {
	stream << MSG_INTRO << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_ADD << pSymbolAdd << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_REMOVE << pSymbolRemove << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_NEW << pSymbolChanceNew << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_ROTATION << pSymbolChanceRotation << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_SEED << pSymbolChanceSeed << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_STEP << pSymbolChanceStep << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_CONSTANT << pSymbolChanceConstant << std::endl;
	stream << MSG_PREFIX_P_SYMBOL_CHANCE_LEAF << pSymbolChanceLeaf << std::endl;
	stream << MSG_PREFIX_P_BRANCH_ADD << pBranchAdd << std::endl;
	stream << MSG_PREFIX_P_BRANCH_REMOVE << pBranchRemove << std::endl;
	stream << MSG_PREFIX_P_LEAF_ADD << pLeafAdd << std::endl;
	stream << MSG_PREFIX_P_LEAF_REMOVE << pLeafRemove << std::endl;
	stream << MSG_PREFIX_P_RULE_DUPLICATE << pRuleDuplicate << std::endl;
	stream << MSG_PREFIX_P_RULE_ADD << pRuleAdd << std::endl;
	stream << MSG_PREFIX_P_RULE_REMOVE << pRuleRemove << std::endl;
}

float Mutator::getPSymbolAdd() const {
	return pSymbolAdd;
}

float Mutator::getPSymbolRemove() const {
	return pSymbolRemove;
}

float Mutator::getPSymbolChanceNew() const {
	return pSymbolChanceNew;
}

float Mutator::getPSymbolChanceRotation() const {
	return pSymbolChanceRotation;
}

float Mutator::getPSymbolChanceSeed() const {
	return pSymbolChanceSeed;
}

float Mutator::getPSymbolChanceStep() const {
	return pSymbolChanceStep;
}

float Mutator::getPSymbolChanceConstant() const {
	return pSymbolChanceConstant;
}

float Mutator::getPSymbolChanceLeaf() const {
	return pSymbolChanceLeaf;
}

float Mutator::getPBranchAdd() const {
	return pBranchAdd;
}

float Mutator::getPBranchRemove() const {
	return pBranchRemove;
}

float Mutator::getPLeafAdd() const {
	return pLeafAdd;
}

float Mutator::getPLeafRemove() const {
	return pLeafRemove;
}

float Mutator::getPRuleDuplicate() const {
	return pRuleDuplicate;
}

float Mutator::getPRuleAdd() const {
	return pRuleAdd;
}

float Mutator::getPRuleRemove() const {
	return pRuleRemove;
}

void Mutator::setPSymbolAdd(const float pSymbolAdd) {
	this->pSymbolAdd = pSymbolAdd;
}

void Mutator::setPSymbolRemove(const float pSymbolRemove) {
	this->pSymbolRemove = pSymbolRemove;
}

void Mutator::setPSymbolChanceNew(const float pSymbolChanceNew) {
	this->pSymbolChanceNew = pSymbolChanceNew;
}

void Mutator::setPSymbolChanceRotation(const float pSymbolChanceRotation) {
	this->pSymbolChanceRotation = pSymbolChanceRotation;
}

void Mutator::setPSymbolChanceSeed(const float pSymbolChanceSeed) {
	this->pSymbolChanceSeed = pSymbolChanceSeed;
}

void Mutator::setPSymbolChanceStep(const float pSymbolChanceStep) {
	this->pSymbolChanceStep = pSymbolChanceStep;
}

void Mutator::setPSymbolChanceConstant(const float pSymbolChanceConstant) {
	this->pSymbolChanceConstant = pSymbolChanceConstant;
}

void Mutator::setPSymbolChanceLeaf(const float pSymbolChanceLeaf) {
	this->pSymbolChanceLeaf = pSymbolChanceLeaf;
}

void Mutator::setPBranchAdd(const float pBranchAdd) {
	this->pBranchAdd = pBranchAdd;
}

void Mutator::setPBranchRemove(const float pBranchRemove) {
	this->pBranchRemove = pBranchRemove;
}

void Mutator::setPLeafAdd(const float pLeafAdd) {
	this->pLeafAdd = pLeafAdd;
}

void Mutator::setPLeafRemove(const float pLeafRemove) {
	this->pLeafRemove = pLeafRemove;
}

void Mutator::setPRuleDuplicate(const float pRuleDuplicate) {
	this->pRuleDuplicate = pRuleDuplicate;
}

void Mutator::setPRuleAdd(const float pRuleAdd) {
	this->pRuleAdd = pRuleAdd;
}

void Mutator::setPRuleRemove(const float pRuleRemove) {
	this->pRuleRemove = pRuleRemove;
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
		case LParse::Legend::LEAF_OPEN:
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
				tokens.emplace_back(LParse::Legend::LEAF_OPEN);

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

	if(chance <= pSymbolChanceRotation + pSymbolChanceSeed + pSymbolChanceStep + pSymbolChanceLeaf)
		return LParse::Legend::LEAF_A;

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

	if(chance <= constraints->getPLeaf() + constraints->getPStep() + constraints->getPSeed() + constraints->getPRotation())
		return constraints->getLeaves()[randomizer.makeInt(0, constraints->getLeaves().size() - 1)];

	return constraints->getConstants()[randomizer.makeInt(0, constraints->getConstants().size() - 1)];
}