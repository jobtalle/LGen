#include "glfwLoader.h"

#include <GLFW/glfw3.h>

using namespace LGen;

bool GLFWLoader::initialized = false;

GLFWLoader::GLFWLoader() {
	if(initialized)
		return;
		
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, MSAA_SAMPLES);
}

GLFWLoader::~GLFWLoader() {
	if(!initialized)
		return;
	
	glfwTerminate();
}
