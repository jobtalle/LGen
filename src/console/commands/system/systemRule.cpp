#include "console/commands/system/systemRule.h"
#include "console/commands/system/rule/systemRuleAdd.h"

using namespace LGen;

const std::string Command::System::Rule::KEYWORD = "rule";

Command::System::Rule::Rule() :
	Command({ KEYWORD }, {
		new Command::System::Rule::Add()
	}) {

}