#include "console/commands/systemNew.h"
#include "workspace/workspaceSystem.h"

using namespace LGen;

const std::string Command::System::New::KEYWORD = "new";
const std::string Command::System::New::FILE = "text/helpSystemNew.txt";

Command::System::New::New() :
	Command({ KEYWORD }, FILE) {

}

void Command::System::New::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	workspace.getSystem().create();
}