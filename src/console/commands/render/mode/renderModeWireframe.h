#pragma once

#include "console/commands/render/mode/renderMode.h"

namespace LGen {
	class Command::Render::Mode::Wireframe final : public Command {
	public:
		Wireframe();

	protected:
		void application(
			const std::vector<std::string> &arguments,
			Console &console) override;

	private:
		static const std::string KEYWORD;
		static const std::string FILE_HELP;
	};
}