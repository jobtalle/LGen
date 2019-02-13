#include "console/commands/system/systemNew.h"

using namespace LGen;

const std::string Command::System::New::KEYWORD = "new";
const std::string Command::System::New::FILE_HELP = "text/helpSystemNew.txt";

Command::System::New::New() :
	Command({ KEYWORD }, FILE_HELP, 0) {

}

void Command::System::New::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	workspace.system.reset(new LParse::System());
}