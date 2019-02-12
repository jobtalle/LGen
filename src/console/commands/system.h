#pragma once

#include "console/command.h"

namespace LGen {
	class Command::System final : public Command {
	public:
		System();

		class New;
		class Print;
		class Generate;
		class Delete;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
	};
};