#include "environmentTerrain.h"
#include "console/commands/environment/terrain/environmentTerrainDropwave.h"
#include "console/commands/environment/terrain/environmentTerrainFlat.h"

using namespace LGen;

const std::string Command::Environment::Terrain::KEYWORD = "terrain";

Command::Environment::Terrain::Terrain() :
	Command({ KEYWORD }, {
		std::make_shared<Command::Environment::Terrain::Dropwave>(),
		std::make_shared<Command::Environment::Terrain::Flat>()
	}) {

}