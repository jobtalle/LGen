#pragma once

#include "../command.h"
#include "../console.h"

class LGen::Command::Exit final : public LGen::Command {
public:
	Exit(Console *console);

protected:
	void application(const std::vector<std::string> arguments) override;

	Console *console;
};