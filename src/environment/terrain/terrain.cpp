#include "terrain.h"

using namespace LGen;

Terrain::Terrain(const float width, const float height) :
	width(width),
	height(height) {

}

float Terrain::getWidth() const {
	return width;
}

float Terrain::getHeight() const {
	return height;
}

float Terrain::get(const float x, const float y) const {
	return sample(x / width, y / height);
}