#include "console.h"
#include "../monitor/monitor.h"

#include <iostream>
#include <string>

L::Console::Console(L::Monitor *monitor) :
	monitor(monitor) {

	thread_.reset(new std::thread(std::bind(&L::Console::thread, this)));
}

L::Console::~Console() {
	thread_->join();
}

void L::Console::thread() {
	std::string input;

	while(std::cin >> input) {
		if(input == "exit") {
			monitor->stop();

			break;
		}
	}
}