#pragma once

#include "lparse.h"

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

		LParse::Sentence mutate(
			const LParse::Sentence &sentence,
			LParse::Randomizer &randomizer,
			bool allowNew,
			const GeneratedSymbols *generated) const;
		LParse::Token makeToken(LParse::Randomizer &randomizer) const;
		LParse::Token makeToken(LParse::Randomizer &randomizer, const GeneratedSymbols *constraints) const;

		const float pSymbolAdd;
		const float pSymbolRemove;
		const float pSymbolChanceNew;
		float pSymbolChanceRotation;
		float pSymbolChanceSeed;
		float pSymbolChanceStep;
		float pSymbolChanceConstant;

		const float pBranchAdd;
		const float pBranchRemove;

		const float pLeafAdd;
		const float pLeafRemove;

		const float pRuleDuplicate;
		const float pRuleAdd;
		const float pRuleRemove;
	};
}