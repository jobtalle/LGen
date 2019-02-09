#pragma once

#include <lgen.h>
#include <thread>
#include <memory>

class L::Console {
public:
	Console(L::Monitor *monitor);
	~Console();

private:
	L::Monitor *monitor;
	std::unique_ptr<std::thread> thread_;

	void thread();
};