#pragma once

#include "simulation/state.h"
#include "simulation/mutator.h"

#include <memory>

namespace LGen {
	class Simulation final {
	public:
		Simulation(
			std::unique_ptr<Mutator> mutator,
			std::unique_ptr<const State> initial);
		Simulation(
			std::unique_ptr<Mutator> mutator, 
			std::unique_ptr<const State> initial,
			std::unique_ptr<const State> state,
			size_t generation);
		Mutator &getMutator() const;
		const State &getInitial() const;
		const State &getState() const;
		size_t getGeneration() const;

	private:
		const std::unique_ptr<Mutator> mutator;
		const std::unique_ptr<const State> initial;
		std::unique_ptr<const State> state;
		size_t generation;
	};
}
