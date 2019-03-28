#pragma once

#include "../environment/environment.h"

#include <memory>

namespace LGen {
	class Simulation final {
	public:
		Simulation() = default;
		void setEnvironment(const std::shared_ptr<Environment> &environment);
		const Environment &getEnvironment() const;

	private:
		std::shared_ptr<Environment> environment;
	};
}
