#include "console/console.h"
#include "monitor/monitor.h"

using namespace LGen;

int main(int argc, char **argv) {
	Monitor monitor("Monitor");
	Console console(&monitor);

	monitor.start();

	return 0;
}