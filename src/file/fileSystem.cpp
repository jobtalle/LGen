#include "file/fileSystem.h"
#include "utils/stringUtils.h"

#include <vector>

using namespace LGen;

static const std::string KEY_AXIOM = "axiom";
static const std::string KEY_RULE_PREFIX = "rule-";

File &LGen::operator<<(File &file, const LParse::System &system) {
	file.set(KEY_AXIOM, system.getAxiom().getString());

	for(size_t i = 0; i < system.getRules().size(); ++i)
		file.set(KEY_RULE_PREFIX + std::to_string(i), system.getRules()[i].getString());

	return file;
}

std::unique_ptr<LParse::System> &LGen::operator<<(std::unique_ptr<LParse::System> &system, const File &file) {
	std::vector<LParse::Rule> rules;
	std::string key;
	size_t i = 0;

	while(key = KEY_RULE_PREFIX + std::to_string(i++), file.keyExists(key)) {
		std::string rule = file.getString(key);
		std::string lhs;
		std::string rhs;

		Utils::String::split(rule, LParse::Rule::CONNECTIVE, lhs, rhs);

		rules.emplace_back(lhs, rhs);
	}

	system = std::make_unique<LParse::System>();

	system->setAxiom(file.getString(KEY_AXIOM));
	system->setRules(rules);

	return system;
}