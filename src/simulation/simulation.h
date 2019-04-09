#pragma once

#include "simulation/state.h"
#include "simulation/mutator.h"
#include "console/console.h"

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
			std::unique_ptr<State> state,
			size_t generation);
		Mutator &getMutator() const;
		const State &getInitial() const;
		const State &getState() const;
		size_t getGeneration() const;
		void advance(Console &console);
		void revert();
		void reseed() const;

	private:
		const std::unique_ptr<Mutator> mutator;
		const std::unique_ptr<const State> initial;
		std::unique_ptr<State> state;
		size_t generation;
	};
}
