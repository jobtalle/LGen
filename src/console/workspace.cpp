#include "workspace.h"

#include <thread>

using namespace LGen;

Workspace::Workspace() :
	threadCount(std::thread::hardware_concurrency()) {
	if(threadCount == 0)
		threadCount = THREAD_COUNT_DEFAULT;
}
