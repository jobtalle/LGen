#pragma once

#include "console/command.h"
#include "console/console.h"

class LGen::Command::Exit final : public LGen::Command {
public:
	Exit(Console *console);

protected:
	void application(const std::vector<std::string> arguments) override;

	Console *console;
};