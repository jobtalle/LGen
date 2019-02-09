#include <iostream>

#include "console/console.h"
#include "monitor/monitor.h"

int main(int argc, char **argv) {
	L::Monitor monitor("Monitor");
	L::Console console(&monitor);

	monitor.start();

	return 0;
}