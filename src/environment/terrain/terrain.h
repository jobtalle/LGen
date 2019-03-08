#pragma once

#include <string>

namespace LGen {
	class Terrain {
	public:
		Terrain(const std::string &type, const float width, const float height);
		virtual ~Terrain() = default;
		const std::string &getType() const;
		float getWidth() const;
		float getHeight() const;
		float get(const float x, const float y) const;

	protected:
		virtual float sample(const float x, const float y) const = 0;

	private:
		const std::string type;
		const float width;
		const float height;
	};
}