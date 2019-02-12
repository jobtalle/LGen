#include "workspace/workspaceSystem.h"

using namespace LGen;

void Workspace::System::create() {
	system.reset(new LParse::System());
}

void Workspace::System::destroy() {
	system.reset(nullptr);
}