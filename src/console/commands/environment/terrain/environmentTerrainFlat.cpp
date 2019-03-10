#include "environmentTerrainFlat.h"
#include "environment/terrain/terrainFlat.h"

using namespace LGen;

const std::string Command::Environment::Terrain::Flat::KEYWORD = "flat";
const std::string Command::Environment::Terrain::Flat::FILE_HELP = "text/helpEnvironmentTerrainFlat.txt";

Command::Environment::Terrain::Flat::Flat() :
	Command({ KEYWORD }, FILE_HELP, 2) {

}

void Command::Environment::Terrain::Flat::application(
	const std::vector<std::string> arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	try {
		auto width = std::stof(arguments[ARG_WIDTH]);
		auto height = std::stof(arguments[ARG_HEIGHT]);

		workspace.environment->setTerrain(std::make_shared<TerrainFlat>(width, height));
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}