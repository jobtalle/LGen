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
#include "console/commands/system/systemExposure.h"

using namespace LGen;

const std::string Command::System::KEYWORD = "system";
const std::string Command::System::ALIAS = "sys";
const std::string Command::System::MSG_NO_SYSTEM = "No system is loaded.";

Command::System::System() :
	Command({ KEYWORD, ALIAS }, {
		std::make_shared<New>(),
		std::make_shared<Print>(),
		std::make_shared<Generate>(),
		std::make_shared<Axiom>(),
		std::make_shared<Iterations>(),
		std::make_shared<Rule>(),
		std::make_shared<Delete>(),
		std::make_shared<Save>(),
		std::make_shared<Load>(),
		std::make_shared<Render>(),
		std::make_shared<New>(),
		std::make_shared<Exposure>()
	}) {

}