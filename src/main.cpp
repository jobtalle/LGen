#include <iostream>

#include "console/console.h"
#include "monitor/monitor.h"

int main(int argc, char **argv) {
	LGen::Monitor monitor("Monitor");
	LGen::Console console(&monitor);

	monitor.start();

	return 0;
}