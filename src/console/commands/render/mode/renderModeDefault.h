#pragma once

#include "console/commands/render/mode/renderMode.h"

namespace LGen {
	class Command::Render::Mode::Default final : public Command {
	public:
		Default();

	protected:
		void application(
			const std::vector<std::string> arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string ALIAS;
		static const std::string FILE_HELP;
	};
};