#include "workspace/workspace.h"

using namespace LGen;

Workspace::Workspace() :
	randomizer(std::random_device()()),
	systemIterations(ITERATIONS_DEFAULT) {

}