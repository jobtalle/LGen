#include "file/fileSystem.h"
#include "utils/stringUtils.h"

#include <sstream>
#include <vector>

using namespace LGen;

const std::string FileSystem::KEY_AXIOM = "axiom";
const std::string FileSystem::KEY_RULE_PREFIX = "rule-";

File FileSystem::serialize(const LParse::System& system) {
	std::stringstream axiom;
	File file;

	axiom << system.getAxiom();

	file.set(KEY_AXIOM, axiom.str());

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
	std::string key;
	size_t i = 0;

	while(key = KEY_RULE_PREFIX + std::to_string(i++), file.keyExists(key)) {
		std::string rule = file.getString(key);
		std::string lhs;
		std::string rhs;

		Utils::String::split(rule, LParse::Rule::CONNECTIVE, lhs, rhs);

		rules.push_back(LParse::Rule(lhs, rhs));
	}

	system.setAxiom(file.getString(KEY_AXIOM));
	system.setRules(rules);

	return system;
}
