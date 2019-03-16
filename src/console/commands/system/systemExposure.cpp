#include "systemExposure.h"

using namespace LGen;

const std::string Command::System::Exposure::KEYWORD = "exposure";
const std::string Command::System::Exposure::ALIAS = "exp";
const std::string Command::System::Exposure::FILE_HELP = "text/helpSystemExposure.txt";

Command::System::Exposure::Exposure() :
	Command({ KEYWORD, ALIAS }, FILE_HELP, 0) {
	
}

void Command::System::Exposure::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	
}