#pragma once

#include "../environment/environment.h"

#include <memory>

namespace LGen {
	class Simulation final {
	public:
		Simulation() = default;
		void setEnvironment(std::unique_ptr<const Environment> environment);
		const Environment &getEnvironment() const;

	private:
		std::unique_ptr<const Environment> environment;
	};
}
