#include "console/commands/system/systemSave.h"
#include "file/fileSystem.h"

using namespace LGen;

const std::string Command::System::Save::KEYWORD = "save";
const std::string Command::System::Save::FILE_HELP = "text/helpSystemSave.txt";

Command::System::Save::Save() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::System::Save::application(
	const std::vector<std::string> arguments,
	Console &console,
	Workspace &workspace) {
	const File::System file(*workspace.system);

	file.save(arguments[ARG_FILE]);
}