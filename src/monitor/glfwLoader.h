#pragma once

#include <GLFW/glfw3.h>

namespace LGen {
	class GLFWLoader final {
	public:
		GLFWLoader();
		~GLFWLoader();
		
	private:
		static const size_t GL_VERSION_MAJOR = 4;
		static const size_t GL_VERSION_MINOR = 4;
		static const size_t MSAA_SAMPLES = 4;
	
		static bool initialized;
	};
};
