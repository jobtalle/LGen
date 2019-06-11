#pragma once

#include "console/command.h"

namespace LGen {
	class Command::Environment final : public Command {
	public:
		Environment();

		class New;
		class Delete;
		class Render;
		class Terrain;
		class Save;
		class Load;
		class Initialize;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string MSG_NO_ENVIRONMENT;
		static const std::string MSG_ENVIRONMENT_INCOMPLETE;
	};
}