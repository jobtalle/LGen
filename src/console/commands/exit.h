#pragma once

#include "../command.h"
#include "../console.h"

class L::Command::Exit final : public L::Command {
public:
	Exit(Console *console);

protected:
	void application(const std::vector<std::string> arguments) override;

	Console *console;
};