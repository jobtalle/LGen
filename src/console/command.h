#pragma once

#include "input.h"

#include <lgen.h>
#include <vector>
#include <string>

class L::Command {
public:
	Command(const std::vector<std::string> triggers);
	bool apply(const Input &input);

	class Exit;

protected:
	bool applicable(const std::string input) const;
	virtual void application(const std::vector<std::string> input) = 0;

private:
	const std::vector<std::string> triggers;
};