#include "monitor.h"

#include <iostream>

const size_t L::Monitor::DEFAULT_WIDTH = 1024;
const size_t L::Monitor::DEFAULT_HEIGHT = 768;
const size_t L::Monitor::GL_VERSION_MAJOR = 4;
const size_t L::Monitor::GL_VERSION_MINOR = 4;

static size_t monitorCount = 0;

L::Monitor::Monitor(const char *title) {
	if(monitorCount++ == 0)
		glfwStart();

	window_ = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, title, NULL, NULL);
	terminate_ = false;

	glfwMakeContextCurrent(window_);
}

L::Monitor::~Monitor() {
	glfwDestroyWindow(window_);

	if(--monitorCount == 0)
		glfwStop();
}

void L::Monitor::start() {
	while(!terminate_)
		poll();
}

void L::Monitor::stop() {
	terminate_ = true;
}

void L::Monitor::glfwStart() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void L::Monitor::glfwStop() {
	glfwTerminate();
}

void L::Monitor::poll() {
	glfwSwapBuffers(window_);
	glfwPollEvents();
}