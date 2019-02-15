#include "file/fileSystem.h"

#include <sstream>
#include <iostream>

using namespace LGen::File;

const std::string System::KEY_AXIOM = "axiom";
const std::string System::KEY_ITERATIONS = "iterations";
const std::string System::KEY_RULE_COUNT = "rule-count";
const std::string System::KEY_RULE_PREFIX = "rule-";

System::System(const std::string &file) :
	Config(file) {

}

System::System(const LParse::System &system) {
	std::stringstream axiom;
	std::stringstream iterations;
	std::stringstream ruleCount;

	axiom << system.getAxiom();
	iterations << system.getIterations();
	ruleCount << system.getRules().size();

	set(KEY_AXIOM, axiom.str());
	set(KEY_ITERATIONS, iterations.str());
	set(KEY_RULE_COUNT, ruleCount.str());

	for(size_t i = 0; i < system.getRules().size(); ++i) {
		std::stringstream rule;

		rule << system.getRules()[i];

		set(KEY_RULE_PREFIX + std::to_string(i), rule.str());
	}
}