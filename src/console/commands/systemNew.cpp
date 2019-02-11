#include "console/commands/systemNew.h"

using namespace LGen;

const std::string Command::System::New::KEYWORD = "new";
const std::string Command::System::New::FILE = "text/helpSystemNew.txt";

Command::System::New::New() :
	Command({ KEYWORD }, FILE) {

}