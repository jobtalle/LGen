#include <iostream>
#include <random>

#include "console/console.h"
#include "monitor/monitor.h"

#include "rule.h"

int main(int argc, char **argv) {
	LGen::Monitor monitor("Monitor");
	LGen::Console console(&monitor);

	monitor.start();

	return 0;
}