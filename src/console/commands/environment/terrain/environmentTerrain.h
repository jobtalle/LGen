#pragma once

#include "console/commands/environment/environment.h"

namespace LGen {
	class Command::Environment::Terrain final : public Command {
	public:
		Terrain();

		class Dropwave;
		class Flat;

	private:
		static const std::string KEYWORD;
	};
}