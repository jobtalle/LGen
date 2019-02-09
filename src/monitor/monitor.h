#pragma once

#include <lgen.h>
#include <string>
#include <thread>
#include <memory>
#include <atomic>
#include <GLFW/glfw3.h>

class L::Monitor final {
public:
	Monitor(const char *title);
	~Monitor();
	void start();
	void stop();

private:
	static const size_t DEFAULT_WIDTH;
	static const size_t DEFAULT_HEIGHT;
	static const size_t GL_VERSION_MAJOR;
	static const size_t GL_VERSION_MINOR;

	static void glfwStart();
	static void glfwStop();
	void poll();

	GLFWwindow *window;
	std::atomic<bool> terminate;
};