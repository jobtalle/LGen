#pragma once

#include "console/command.h"

namespace LGen {
	class Command::System final : public Command {
	public:
		System();

		class New;
		class Print;
		class Generate;
		class Axiom;
		class Iterations;
		class Delete;
		class Rule;
		class Save;
		class Load;
		class Render;
		class Exposure;
		class Selected;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string MSG_NO_SYSTEM;
	};
}