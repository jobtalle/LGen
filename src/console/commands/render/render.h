#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Render final : public Command {
	public:
		Render();

		class Default;
		class Wireframe;

	private:
		static const std::string KEYWORD;
	};
};