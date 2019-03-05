#pragma once

#include "console/commands/render/render.h"

namespace LGen {
	class Command::Render::Mode final : public Command	{
	public:
		Mode();

		class Default;
		class Wireframe;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
	};
};