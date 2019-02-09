#pragma once

#include "../monitor/monitor.h"
#include "command.h"

#include <thread>
#include <memory>
#include <vector>

class L::Console {
public:
	Console(L::Monitor *monitor);
	~Console();
	void stop();

private:
	static const std::string MSG_NOT_RECOGNIZED;

	std::vector<L::Command*> commands;
	L::Monitor *monitor;
	std::unique_ptr<std::thread> thread;
	bool terminate = false;

	void loop();
	void makeCommands();
};