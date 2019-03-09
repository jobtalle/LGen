#pragma once

#include "console/command.h"
#include "environment/environment.h"

#include <memory>
#include <random>

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

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string MSG_NO_ENVIRONMENT;
		static const std::string MSG_ENVIRONMENT_INCOMPLETE;

		static struct Workspace {
			Workspace();

			std::mt19937 randomizer;
			std::unique_ptr<LGen::Environment> environment;
		} workspace;
	};
}