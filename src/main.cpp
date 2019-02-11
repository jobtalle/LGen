#include <iostream>
#include <random>

#include "console/console.h"
#include "monitor/monitor.h"

#include "rule.h"

int main(int argc, char **argv) {
	std::random_device randomDevice;
	std::mt19937 randomizer(randomDevice());

	const LParse::Rule r1(
		LParse::Sentence({ 'A' }),
		LParse::Sentence({ 'A', 'B', 'B' }));
	const LParse::Rule r2(
		LParse::Sentence({ 'B', 'B' }),
		LParse::Sentence({ 'A' }));
	const LParse::Rule r3(
		LParse::Sentence({ 'B', 'B' }),
		LParse::Sentence({ 'C' }));

	LParse::Sentence axiom({ 'A', 'B', 'A' });

	std::cout << "Rule 1: " << r1 << std::endl;
	std::cout << "Rule 2: " << r2 << std::endl;
	std::cout << "Rule 3: " << r3 << std::endl;
	std::cout << "Axiom: " << axiom << std::endl;

	for(int i = 0; i < 30; ++i) {
		std::cout << "Iteration " << i << std::endl;

		axiom.apply({ r1, r2, r3 }, randomizer);
	}

	std::cout << axiom << std::endl;

	LGen::Monitor monitor("Monitor");
	LGen::Console console(&monitor);

	monitor.start();

	return 0;
}