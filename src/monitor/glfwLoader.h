#pragma once

#include <GLFW/glfw3.h>

namespace LGen {
	class GLFWLoader final {
	public:
		GLFWLoader(const size_t width, const size_t height, const char *title);
		~GLFWLoader();
		
		GLFWwindow *getWindow() const;
		void makeCurrent() const;

	private:
		static const size_t GL_VERSION_MAJOR = 4;
		static const size_t GL_VERSION_MINOR = 4;
		static const size_t MSAA_SAMPLES = 4;
		static size_t initialized;

		GLFWwindow *window;

		static void initialize();
		static void free();
	};
}