#include "timer.h"

using namespace LGen;

Timer::Timer() :
	time(clock()) {
	
}

void Timer::start() {
	time = clock();
}

double Timer::get() const {
	return double(clock() - time) / CLOCKS_PER_SEC;
}