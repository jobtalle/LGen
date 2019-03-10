#pragma once

#include "console/commands/environment/environment.h"

namespace LGen {
	class Command::Environment::Render final : public Command {
	public:
		Render();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
	};
}