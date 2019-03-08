#include "file/fileSystem.h"
#include "utils/stringUtils.h"

#include <sstream>
#include <vector>

using namespace LGen;

const std::string FileSystem::KEY_AXIOM = "axiom";
const std::string FileSystem::KEY_RULE_COUNT = "rule-count";
const std::string FileSystem::KEY_RULE_PREFIX = "rule-";

File FileSystem::serialize(const LParse::System& system) {
	std::stringstream axiom;
	File file;

	axiom << system.getAxiom();

	file.set(KEY_AXIOM, axiom.str());
	file.set(KEY_RULE_COUNT, static_cast<int>(system.getRules().size()));

	for(size_t i = 0; i < system.getRules().size(); ++i) {
		std::stringstream rule;

		rule << system.getRules()[i];

		file.set(KEY_RULE_PREFIX + std::to_string(i), rule.str());
	}

	return file;
}

LParse::System FileSystem::deserialize(const File& file) {
	LParse::System system;

	std::vector<LParse::Rule> rules;
	const size_t rule_count = file.getInt(KEY_RULE_COUNT);

	for(size_t i = 0; i < rule_count; ++i) {
		std::string rule = file.getString(KEY_RULE_PREFIX + std::to_string(i));
		std::string lhs;
		std::string rhs;

		Utils::String::split(rule, LParse::Rule::CONNECTIVE, lhs, rhs);

		rules.push_back(LParse::Rule(lhs, rhs));
	}

	system.setAxiom(file.getString(KEY_AXIOM));
	system.setRules(rules);

	return system;
}
