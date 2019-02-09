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
	void dumpFile(const std::string file);

private:
	static const std::string MSG_NOT_RECOGNIZED;
	static const std::string FILE_INTRO;
	static const std::string COMMAND_PREFIX;

	std::vector<L::Command*> commands;
	L::Monitor *monitor;
	std::unique_ptr<std::thread> thread;
	bool terminate = false;

	void loop();
	void makeCommands();
};