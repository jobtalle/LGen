#include "console/commands/system/systemLoad.h"
#include "file/fileSystem.h"

using namespace LGen;

const std::string Command::System::Load::KEYWORD = "load";
const std::string Command::System::Load::FILE_HELP = "text/helpSystemLoad.txt";
const std::string Command::System::Load::MSG_ERROR = "Error while loading the system.";

Command::System::Load::Load() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::System::Load::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	try {
		const File::System file(arguments[ARG_FILE]);

		workspace.system = std::make_unique<LParse::System>(file.getSystem());
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}
