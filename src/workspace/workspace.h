#pragma once

#include <memory>

namespace LGen {
	class Workspace final {
	public:
		class System;

		Workspace();
		~Workspace();
		System &getSystem() const;
	private:
		std::unique_ptr<System> system;
	};
};