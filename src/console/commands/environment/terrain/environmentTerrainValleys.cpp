#include "environmentTerrainValleys.h"
#include "environment/terrain/terrainValleys.h"

using namespace LGen;

const std::string Command::Environment::Terrain::Valleys::KEYWORD = "valleys";
const std::string Command::Environment::Terrain::Valleys::FILE_HELP = "text/helpEnvironmentTerrainValleys.txt";

Command::Environment::Terrain::Valleys::Valleys() :
	Command({ KEYWORD }, FILE_HELP, 3) {
	
}

void Command::Environment::Terrain::Valleys::application(
	const std::vector<std::string> &arguments,
	Console &console) {
	if(!workspace.environment) {
		console << MSG_NO_ENVIRONMENT << std::endl;

		return;
	}

	try {
		const auto width = std::stof(arguments[ARG_WIDTH]);
		const auto height = std::stof(arguments[ARG_HEIGHT]);
		const auto resolution = std::stof(arguments[ARG_RESOLUTION]);

		workspace.environment->setTerrain(std::make_unique<TerrainValleys>(width, height, resolution));
	}
	catch(...) {
		console << MSG_INVALID_INPUT << std::endl;
	}
}

