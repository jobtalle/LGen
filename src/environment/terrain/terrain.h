#pragma once

namespace LGen {
	class Terrain {
	public:
		Terrain(const float width, const float height);
		virtual ~Terrain() = default;
		float getWidth() const;
		float getHeight() const;
		float get(const float x, const float y) const;

	protected:
		virtual float sample(const float x, const float y) const = 0;

	private:
		const float width;
		const float height;
	};
}