#include "console/commands/system/rule/systemRuleRemove.h"

using namespace LGen;

const std::string Command::System::Rule::Remove::KEYWORD = "remove";
const std::string Command::System::Rule::Remove::FILE_HELP = "text/helpSystemRuleRemove.txt";
const std::string Command::System::Rule::Remove::MSG_RULE_DOES_NOT_EXIST = "The given rule does not exist.";

Command::System::Rule::Remove::Remove() :
	Command({ KEYWORD }, FILE_HELP, 2) {

}

void Command::System::Rule::Remove::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	bool success = false;
	const LParse::Rule rule(arguments[ARG_LHS], arguments[ARG_RHS]);
	std::vector<LParse::Rule> rules = workspace.system->getRules();

	for(size_t i = 0; i < rules.size(); ++i) {
		if(rules[i] == rule) {
			rules.erase(rules.begin() + i);
			success = true;

			break;
		}
	}

	if(success)
		workspace.system->setRules(rules);
	else
		console << MSG_RULE_DOES_NOT_EXIST << std::endl;
}