#include "glfwLoader.h"

#include <GLFW/glfw3.h>

using namespace LGen;

size_t GLFWLoader::initialized = 0;

GLFWLoader::GLFWLoader(const size_t width, const size_t height, const char *title) {
	if(initialized++ == 0)
		initialize();

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	makeCurrent();
}

GLFWLoader::~GLFWLoader() {
	glfwDestroyWindow(window);

	if(--initialized == 0)
		glfwTerminate();
}

GLFWwindow *GLFWLoader::getWindow() const {
	return window;
}

void GLFWLoader::makeCurrent() const {
	glfwMakeContextCurrent(window);
}

void GLFWLoader::initialize() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, MSAA_SAMPLES);
}

void GLFWLoader::free() {
	glfwTerminate();
}