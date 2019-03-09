#include "system.h"
#include "console/commands/system/systemNew.h"
#include "console/commands/system/systemPrint.h"
#include "console/commands/system/systemGenerate.h"
#include "console/commands/system/systemAxiom.h"
#include "console/commands/system/systemDelete.h"
#include "console/commands/system/systemIterations.h"
#include "console/commands/system/rule/systemRule.h"
#include "console/commands/system/systemSave.h"
#include "console/commands/system/systemLoad.h"
#include "console/commands/system/systemRender.h"

using namespace LGen;

const std::string Command::System::KEYWORD = "system";
const std::string Command::System::ALIAS = "sys";
const std::string Command::System::MSG_NO_SYSTEM = "No system is loaded.";

Command::System::System() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<Command::System::New>(),
		std::make_shared<Command::System::Print>(),
		std::make_shared<Command::System::Generate>(),
		std::make_shared<Command::System::Axiom>(),
		std::make_shared<Command::System::Iterations>(),
		std::make_shared<Command::System::Rule>(),
		std::make_shared<Command::System::Delete>(),
		std::make_shared<Command::System::Save>(),
		std::make_shared<Command::System::Load>(),
		std::make_shared<Command::System::Render>(),
		std::make_shared<Command::System::New>()
	}) {

}