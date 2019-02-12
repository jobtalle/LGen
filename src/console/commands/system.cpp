#include "console/commands/system.h"
#include "console/commands/systemNew.h"
#include "console/commands/systemPrint.h"
#include "console/commands/systemGenerate.h"
#include "console/commands/systemDelete.h"

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
		new Command::System::Delete() }) {

}