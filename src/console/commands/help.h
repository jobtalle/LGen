#pragma once

#include "console/command.h"

class LGen::Command::Help final : public LGen::Command {
public:
	Help();

protected:
	void application(const Console &console, const std::vector<std::string> arguments) override;

private:
	static const std::string KEYWORD;
	static const std::string ALIAS;
	static const std::string FILE;
};