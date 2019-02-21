#include "monitor/monitor.h"
#include "lrender.h"

#include <functional>

using namespace LGen;

static size_t monitorCount = 0;

Monitor::Monitor(const char *title) {
	if(monitorCount++ == 0)
		glfwStart();

	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, title, NULL, NULL);
	terminate = false;

	glfwSetWindowAttrib(window, GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
	glfwMakeContextCurrent(window);

	renderer.reset(new LRender::Renderer(DEFAULT_WIDTH, DEFAULT_HEIGHT));
	glfwSetWindowUserPointer(window, renderer.get());

	glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height) {
		static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->setSize(width, height);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow *window, double x, double y) {
		static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseMove(x, y);
	});

	glfwSetScrollCallback(window, [](GLFWwindow *window, double dx, double dy) {
		if(dy > 0)
			static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->scrollUp();
		else
			static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->scrollDown();
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods) {
		switch(button) {
		case MOUSE_BUTTON_DRAG:
			switch(action) {
			case MOUSE_ACTION_DRAG_START:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mousePress(LRender::Renderer::MOUSE_DRAG);

				break;
			case MOUSE_ACTION_DRAG_STOP:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseRelease(LRender::Renderer::MOUSE_DRAG);

				break;
			}

			break;
		case MOUSE_BUTTON_PAN:
			switch(action) {
			case MOUSE_ACTION_PAN_START:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mousePress(LRender::Renderer::MOUSE_PAN);

				break;
			case MOUSE_ACTION_PAN_STOP:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseRelease(LRender::Renderer::MOUSE_PAN);

				break;
			}
			break;
		}
	});
}

Monitor::~Monitor() {
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

		renderer->update();

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
	glfwWindowHint(GLFW_SAMPLES, MSAA_SAMPLES);
}

void Monitor::glfwStop() {
	glfwTerminate();
}

void Monitor::poll() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}