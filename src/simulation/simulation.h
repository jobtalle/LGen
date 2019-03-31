#pragma once

#include "simulation/state.h"

#include <memory>

namespace LGen {
	class Simulation final {
	public:
		Simulation(std::unique_ptr<const State> initial);
		Simulation(std::unique_ptr<const State> initial, std::unique_ptr<const State> state);
		const State &getInitial() const;
		const State &getState() const;

	private:
		std::unique_ptr<const State> initial;
		std::unique_ptr<const State> state;
	};
}
