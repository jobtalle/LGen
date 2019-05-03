#include "fileMutator.h"

using namespace LGen;

static const std::string KEY_P_SYMBOL_ADD = "symbol-add";
static const std::string KEY_P_SYMBOL_REMOVE = "symbol-remove";
static const std::string KEY_P_SYMBOL_CHANCE_NEW = "symbol-chance-new";
static const std::string KEY_P_SYMBOL_CHANCE_ROTATION = "symbol-chance-rotation";
static const std::string KEY_P_SYMBOL_CHANCE_SEED = "symbol-chance-seed";
static const std::string KEY_P_SYMBOL_CHANCE_STEP = "symbol-chance-step";
static const std::string KEY_P_SYMBOL_CHANCE_CONSTANT = "symbol-chance-constant";
static const std::string KEY_P_SYMBOL_CHANCE_LEAF = "symbol-chance-leaf";
static const std::string KEY_P_BRANCH_ADD = "branch-add";
static const std::string KEY_P_BRANCH_REMOVE = "branch-remove";
static const std::string KEY_P_LEAF_ADD = "leaf-add";
static const std::string KEY_P_LEAF_REMOVE = "leaf-remove";
static const std::string KEY_P_RULE_DUPLICATE = "rule-duplicate";
static const std::string KEY_P_RULE_ADD = "rule-add";
static const std::string KEY_P_RULE_REMOVE = "rule-remove";

File &LGen::operator<<(File &file, const Mutator &mutator) {
	file.set(KEY_P_SYMBOL_ADD, mutator.getPSymbolAdd());
	file.set(KEY_P_SYMBOL_REMOVE, mutator.getPSymbolRemove());
	file.set(KEY_P_SYMBOL_CHANCE_NEW, mutator.getPSymbolChanceNew());
	file.set(KEY_P_SYMBOL_CHANCE_ROTATION, mutator.getPSymbolChanceRotation());
	file.set(KEY_P_SYMBOL_CHANCE_SEED, mutator.getPSymbolChanceSeed());
	file.set(KEY_P_SYMBOL_CHANCE_STEP, mutator.getPSymbolChanceStep());
	file.set(KEY_P_SYMBOL_CHANCE_CONSTANT, mutator.getPSymbolChanceConstant());
	file.set(KEY_P_SYMBOL_CHANCE_LEAF, mutator.getPSymbolChanceLeaf());
	file.set(KEY_P_BRANCH_ADD, mutator.getPBranchAdd());
	file.set(KEY_P_BRANCH_REMOVE, mutator.getPBranchRemove());
	file.set(KEY_P_LEAF_ADD, mutator.getPLeafAdd());
	file.set(KEY_P_LEAF_REMOVE, mutator.getPLeafRemove());
	file.set(KEY_P_RULE_DUPLICATE, mutator.getPRuleDuplicate());
	file.set(KEY_P_RULE_ADD, mutator.getPRuleAdd());
	file.set(KEY_P_RULE_REMOVE, mutator.getPRuleRemove());

	return file;
}

std::unique_ptr<Mutator> &LGen::operator<<(std::unique_ptr<Mutator> &mutator, const File &file) {
	mutator = std::make_unique<Mutator>(
		file.getFloat(KEY_P_SYMBOL_ADD),
		file.getFloat(KEY_P_SYMBOL_REMOVE),
		file.getFloat(KEY_P_SYMBOL_CHANCE_NEW),
		file.getFloat(KEY_P_SYMBOL_CHANCE_ROTATION),
		file.getFloat(KEY_P_SYMBOL_CHANCE_SEED),
		file.getFloat(KEY_P_SYMBOL_CHANCE_STEP),
		file.getFloat(KEY_P_SYMBOL_CHANCE_CONSTANT),
		file.getFloat(KEY_P_SYMBOL_CHANCE_LEAF),
		file.getFloat(KEY_P_BRANCH_ADD),
		file.getFloat(KEY_P_BRANCH_REMOVE),
		file.getFloat(KEY_P_LEAF_ADD),
		file.getFloat(KEY_P_LEAF_REMOVE),
		file.getFloat(KEY_P_RULE_DUPLICATE),
		file.getFloat(KEY_P_RULE_ADD),
		file.getFloat(KEY_P_RULE_REMOVE));

	return mutator;
}