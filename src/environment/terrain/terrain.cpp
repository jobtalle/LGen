#include "terrain.h"

using namespace LGen;

Terrain::Terrain(const std::string &type, const float width, const float height) :
	type(type),
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