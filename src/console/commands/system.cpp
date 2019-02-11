#include "console/commands/system.h"
#include "console/commands/systemNew.h"

using namespace LGen;

const std::string Command::System::KEYWORD = "system";
const std::string Command::System::ALIAS = "sys";

Command::System::System() :
	Command({ KEYWORD, ALIAS }, { new Command::System::New() }) {

}