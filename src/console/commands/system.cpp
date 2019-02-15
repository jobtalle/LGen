#include "console/commands/system.h"
#include "console/commands/system/systemNew.h"
#include "console/commands/system/systemPrint.h"
#include "console/commands/system/systemGenerate.h"
#include "console/commands/system/systemAxiom.h"
#include "console/commands/system/systemDelete.h"
#include "console/commands/system/systemIterations.h"
#include "console/commands/system/systemRule.h"
#include "console/commands/system/systemSave.h"

using namespace LGen;

const std::string Command::System::KEYWORD = "system";
const std::string Command::System::ALIAS = "sys";
const std::string Command::System::MSG_NO_SYSTEM = "No system is loaded.";
const std::string Command::System::MSG_SYSTEM_INCOMPLETE = "The current system is incomplete.";

Command::System::System() :
	Command({ KEYWORD, ALIAS }, {
		new Command::System::New(),
		new Command::System::Print(),
		new Command::System::Generate(),
		new Command::System::Axiom(),
		new Command::System::Iterations(),
		new Command::System::Rule(),
		new Command::System::Delete(),
		new Command::System::Save()
	}) {

}