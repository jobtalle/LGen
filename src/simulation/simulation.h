#pragma once

#include "../environment/environment.h"

#include <memory>

namespace LGen {
	class Simulation final {
	public:
		Simulation() = default;
		Simulation(LParse::Randomizer randomizer);
		void setEnvironment(std::unique_ptr<const Environment> environment);
		const Environment &getEnvironment() const;
		const LParse::Randomizer &getRandomizer() const;

	private:
		LParse::Randomizer randomizer;
		std::unique_ptr<const Environment> environment;
	};
}
