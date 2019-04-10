#pragma once

#include <chrono>

namespace LGen {
	class Timer final {
	public:
		Timer();
		void start();
		double get() const;
	private:
		clock_t time;
	};
}