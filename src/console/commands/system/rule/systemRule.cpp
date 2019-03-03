#include "systemRule.h"
#include "console/commands/system/rule/systemRuleAdd.h"
#include "console/commands/system/rule/systemRuleRemove.h"

using namespace LGen;

const std::string Command::System::Rule::KEYWORD = "rule";
const std::string Command::System::Rule::ALIAS = "r";

Command::System::Rule::Rule() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<Command::System::Rule::Add>(),
		std::make_shared<Command::System::Rule::Remove>()
	}) {

}