#include "console/commands/system/rule/systemRuleAdd.h"

using namespace LGen;

const std::string Command::System::Rule::Add::KEYWORD = "add";
const std::string Command::System::Rule::Add::FILE_HELP = "text/helpSystemRuleAdd.txt";

Command::System::Rule::Add::Add() :
	Command({ KEYWORD }, FILE_HELP, 2) {

}

void Command::System::Rule::Add::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	std::vector<LParse::Rule> rules = workspace.system->getRules();

	rules.push_back(LParse::Rule(arguments[ARG_LHS], arguments[ARG_RHS]));

	workspace.system->setRules(rules);
}