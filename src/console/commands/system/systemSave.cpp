#include "console/commands/system/systemSave.h"
#include "file/fileSystem.h"

using namespace LGen;

const std::string Command::System::Save::KEYWORD = "save";
const std::string Command::System::Save::FILE_HELP = "text/helpSystemSave.txt";
const std::string Command::System::Save::MSG_ERROR = "Error while saving the system.";

Command::System::Save::Save() :
	Command({ KEYWORD }, FILE_HELP, 1) {

}

void Command::System::Save::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.system) {
		console << MSG_NO_SYSTEM << std::endl;

		return;
	}

	try {
		(File() << workspace.system).save(arguments[ARG_FILE]);
	}
	catch(...) {
		console << MSG_ERROR << std::endl;
	}
}