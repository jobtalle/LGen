#include <iostream>
#include <random>

#include "workspace/workspace.h"
#include "console/console.h"
#include "monitor/monitor.h"

#include "rule.h"

int main(int argc, char **argv) {
	LGen::Workspace workspace;
	LGen::Monitor monitor("Monitor");
	LGen::Console console(&monitor, &workspace);

	monitor.start();

	return 0;
}