#pragma once

#include "simulation/state.h"
#include "simulation/mutator.h"
#include "console/console.h"

#include <memory>
#include <cstddef>

namespace LGen {
	class Simulation final {
	public:
		Simulation(
			std::unique_ptr<Mutator> mutator,
			std::unique_ptr<State> initial);
		Simulation(
			std::unique_ptr<Mutator> mutator, 
			std::unique_ptr<State> initial,
			std::unique_ptr<State> state,
			size_t generation);
		Mutator &getMutator() const;
		const State &getInitial() const;
		const State &getState() const;
		float getDensity() const;
		size_t getGeneration() const;
		void setDensity(float density);
		void advance(Console &console, size_t threads);
		void revert();
		void reseed();

	private:
		static const float DENSITY_DEFAULT;

		const std::unique_ptr<Mutator> mutator;
		std::unique_ptr<State> initial;
		std::unique_ptr<State> state;
		size_t generation;
		float density = DENSITY_DEFAULT;
	};
}
