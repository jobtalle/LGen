#include <iostream>
#include <random>

#include "console/console.h"
#include "monitor/monitor.h"

#include "rule.h"

int main(int argc, char **argv) {
	std::random_device randomDevice;
	std::mt19937 randomizer(randomDevice());

	const LParse::Rule r1(
		LParse::Sentence({ LParse::Token('A') }),
		LParse::Sentence({ LParse::Token('A'), LParse::Token('B'), LParse::Token('B') }));
	const LParse::Rule r2(
		LParse::Sentence({ LParse::Token('B'), LParse::Token('B') }),
		LParse::Sentence({ LParse::Token('A') }));
	const LParse::Rule r3(
		LParse::Sentence({ LParse::Token('B'), LParse::Token('B') }),
		LParse::Sentence({ LParse::Token('C') }));

	LParse::Sentence axiom({ LParse::Token('A'), LParse::Token('B'), LParse::Token('A') });

	std::cout << "Axiom: ";
	axiom.print(std::cout);
	std::cout << std::endl;

	for(int i = 0; i < 5; ++i) {
		std::cout << "Iteration " << i << std::endl;

		axiom.apply({ r1, r2, r3 }, randomizer);

		axiom.print(std::cout);
		std::cout << std::endl;
	}

	LGen::Monitor monitor("Monitor");
	LGen::Console console(&monitor);

	monitor.start();

	return 0;
}