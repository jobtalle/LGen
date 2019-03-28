#include "terrain.h"

#include <utility>

using namespace LGen;

Terrain::Terrain(std::string type, const float width, const float height) :
	type(std::move(type)),
	width(width),
	height(height) {

}

const std::string& Terrain::getType() const {
	return type;
}

float Terrain::getWidth() const {
	return width;
}

float Terrain::getHeight() const {
	return height;
}

float Terrain::get(const float x, const float y) const {
	return sample(x, y);
}