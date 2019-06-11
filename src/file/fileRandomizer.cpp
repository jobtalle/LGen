#include "fileRandomizer.h"

using namespace LGen;

static const std::string KEY_STATE = "state";

File &LGen::operator<<(File &file, const LParse::Randomizer &randomizer) {
	file.set(KEY_STATE, randomizer.toString());

	return file;
}

std::unique_ptr<LParse::Randomizer> &LGen::operator<<(std::unique_ptr<LParse::Randomizer> &randomizer, const File &file) {
	randomizer = std::make_unique<LParse::Randomizer>(file.getString(KEY_STATE));
	
	return randomizer;
}