#include "fileMutator.h"

using namespace LGen;

File &LGen::operator<<(File &file, const Mutator &mutator) {
	return file;
}

std::unique_ptr<Mutator> &LGen::operator<<(std::unique_ptr<Mutator> &mutator, const File &file) {
	return mutator;
}