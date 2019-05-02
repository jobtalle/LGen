#pragma once

#include "lparse.h"

#include <iostream>

namespace LGen {
	class Mutator final {
	public:
		Mutator(
			float pSymbolAdd = 0.005f,
			float pSymbolRemove = 0.005f,
			float pSymbolChanceNew = 0.2f,
			float pSymbolChanceRotation = 0.35f, // These probabilities are
			float pSymbolChanceSeed = 0.05f,     // relative to each other,
			float pSymbolChanceStep = 0.4f,      // their total probability
			float pSymbolChanceConstant = 0.2f,  // is 100%.
			float pBranchAdd = 0.002f,
			float pBranchRemove = 0.002f,
			float pLeafAdd = 0.002f,
			float pLeafRemove = 0.002f,
			float pRuleDuplicate = 0.003f,
			float pRuleAdd = 0.001f,
			float pRuleRemove = 0.004f);
		LParse::System mutate(const LParse::System &system, LParse::Randomizer &randomizer) const;
		void print(std::ostream &stream) const;

		float getPSymbolAdd() const;
		float getPSymbolRemove() const;
		float getPSymbolChanceNew() const;
		float getPSymbolChanceRotation() const;
		float getPSymbolChanceSeed() const;
		float getPSymbolChanceStep() const;
		float getPSymbolChanceConstant() const;
		float getPBranchAdd() const;
		float getPBranchRemove() const;
		float getPLeafAdd() const;
		float getPLeafRemove() const;
		float getPRuleDuplicate() const;
		float getPRuleAdd() const;
		float getPRuleRemove() const;

		void setPSymbolAdd(float pSymbolAdd);
		void setPSymbolRemove(float pSymbolRemove);
		void setPSymbolChanceNew(float pSymbolChanceNew);
		void setPSymbolChanceRotation(float pSymbolChanceRotation);
		void setPSymbolChanceSeed(float pSymbolChanceSeed);
		void setPSymbolChanceStep(float pSymbolChanceStep);
		void setPSymbolChanceConstant(float pSymbolChanceConstant);
		void setPBranchAdd(float pBranchAdd);
		void setPBranchRemove(float pBranchRemove);
		void setPLeafAdd(float pLeafAdd);
		void setPLeafRemove(float pLeafRemove);
		void setPRuleDuplicate(float pRuleDuplicate);
		void setPRuleAdd(float pRuleAdd);
		void setPRuleRemove(float pRuleRemove);

	private:
		class GeneratedSymbols final {
		public:
			GeneratedSymbols(
				const std::vector<LParse::Token> &generatedTokens,
				float pStep,
				float pConstant,
				float pRotation,
				float pSeed);
			const std::vector<LParse::Token> &getSteps() const;
			const std::vector<LParse::Token> &getConstants() const;
			const std::vector<LParse::Token> &getRotations() const;
			const std::vector<LParse::Token> &getSeeds() const;
			float getPStep() const;
			float getPConstant() const;
			float getPRotation() const;
			float getPSeed() const;
			bool empty() const;

		private:
			void normalize();

			std::vector<LParse::Token> steps;
			std::vector<LParse::Token> constants;
			std::vector<LParse::Token> rotations;
			std::vector<LParse::Token> seeds;
			float pStep;
			float pConstant;
			float pRotation;
			float pSeed;
		};

		static const size_t SENTENCE_LENGTH_LIMIT = 10;
		static const std::string MSG_INTRO;
		static const std::string MSG_PROPERTY_INDENTATION;
		static const std::string MSG_PREFIX_P_SYMBOL_ADD;
		static const std::string MSG_PREFIX_P_SYMBOL_REMOVE;
		static const std::string MSG_PREFIX_P_SYMBOL_CHANCE_NEW;
		static const std::string MSG_PREFIX_P_SYMBOL_CHANCE_ROTATION;
		static const std::string MSG_PREFIX_P_SYMBOL_CHANCE_SEED;
		static const std::string MSG_PREFIX_P_SYMBOL_CHANCE_STEP;
		static const std::string MSG_PREFIX_P_SYMBOL_CHANCE_CONSTANT;
		static const std::string MSG_PREFIX_P_BRANCH_ADD;
		static const std::string MSG_PREFIX_P_BRANCH_REMOVE;
		static const std::string MSG_PREFIX_P_LEAF_ADD;
		static const std::string MSG_PREFIX_P_LEAF_REMOVE;
		static const std::string MSG_PREFIX_P_RULE_DUPLICATE;
		static const std::string MSG_PREFIX_P_RULE_ADD;
		static const std::string MSG_PREFIX_P_RULE_REMOVE;

		LParse::Sentence mutate(
			const LParse::Sentence &sentence,
			LParse::Randomizer &randomizer,
			bool allowNew,
			const GeneratedSymbols *generated) const;
		LParse::Token makeToken(LParse::Randomizer &randomizer) const;
		LParse::Token makeToken(LParse::Randomizer &randomizer, const GeneratedSymbols *constraints) const;

		float pSymbolAdd;
		float pSymbolRemove;
		float pSymbolChanceNew;
		float pSymbolChanceRotation;
		float pSymbolChanceSeed;
		float pSymbolChanceStep;
		float pSymbolChanceConstant;
		float pBranchAdd;
		float pBranchRemove;
		float pLeafAdd;
		float pLeafRemove;
		float pRuleDuplicate;
		float pRuleAdd;
		float pRuleRemove;
	};
}