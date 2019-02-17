#include "monitor/monitor.h"

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

	glfwSetWindowAttrib(window, GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
	glfwMakeContextCurrent(window);

	renderer = new LRender::Renderer();
}

Monitor::~Monitor() {
	delete renderer;

	glfwDestroyWindow(window);

	if(--monitorCount == 0)
		glfwStop();
}

void Monitor::start() {
	while(!terminate) {
		poll();

		if(glfwWindowShouldClose(window)) {
			glfwHideWindow(window);
			glfwSetWindowShouldClose(window, GLFW_FALSE);
		}

		if(glfwGetWindowAttrib(window, GLFW_VISIBLE))
			renderer->render();
	}
}

void Monitor::stop() {
	terminate = true;
}

void Monitor::setScene(std::shared_ptr<LRender::Scene> scene) {
	if(!glfwGetWindowAttrib(window, GLFW_VISIBLE))
		glfwShowWindow(window);

	renderer->setScene(scene);
}

void Monitor::glfwStart() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GL_VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GL_VERSION_MINOR);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Monitor::glfwStop() {
	glfwTerminate();
}

void Monitor::poll() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}