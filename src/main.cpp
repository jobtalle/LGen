#include <iostream>
#include <random>

#include "workspace/workspace.h"
#include "console/console.h"
#include "monitor/monitor.h"

using namespace LGen;

int main(int argc, char **argv) {
	Workspace workspace;
	Monitor monitor("Monitor");
	Console console(&monitor, &workspace);

	monitor.start();

	return 0;
}