#include "workspace/workspace.h"
#include "workspace/workspaceSystem.h"

using namespace LGen;

Workspace::Workspace() :
	system(new Workspace::System()) {

}

Workspace::~Workspace() {

}

Workspace::System *Workspace::getSystem() const {
	return system.get();
}