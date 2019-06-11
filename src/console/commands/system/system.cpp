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
#include "console/commands/system/systemSelected.h"

using namespace LGen;

const std::string Command::System::KEYWORD = "system";
const std::string Command::System::ALIAS = "sys";
const std::string Command::System::MSG_NO_SYSTEM = "No system is loaded.";

Command::System::System() :
	Command({ KEYWORD, ALIAS }, {
		std::make_unique<New>(),
		std::make_unique<Print>(),
		std::make_unique<Generate>(),
		std::make_unique<Axiom>(),
		std::make_unique<Iterations>(),
		std::make_unique<Rule>(),
		std::make_unique<Delete>(),
		std::make_unique<Save>(),
		std::make_unique<Load>(),
		std::make_unique<Render>(),
		std::make_unique<New>(),
		std::make_unique<Exposure>(),
		std::make_unique<Selected>()
	}) {

}