#include "monitor.h"

#include <iostream>

using namespace LGen;

const size_t Monitor::DEFAULT_WIDTH = 1024;
const size_t Monitor::DEFAULT_HEIGHT = 768;
const size_t Monitor::GL_VERSION_MAJOR = 4;
const size_t Monitor::GL_VERSION_MINOR = 4;

static size_t monitorCount = 0;

Monitor::Monitor(const char *title) {
	if(monitorCount++ == 0)
		glfwStart();

	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, title, NULL, NULL);
	terminate = false;

	glfwMakeContextCurrent(window);
}

Monitor::~Monitor() {
	glfwDestroyWindow(window);

	if(--monitorCount == 0)
		glfwStop();
}

void Monitor::start() {
	while(!terminate)
		poll();
}

void Monitor::stop() {
	terminate = true;
}

void Monitor::glfwStart() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Monitor::glfwStop() {
	glfwTerminate();
}

void Monitor::poll() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}