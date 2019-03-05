#include "monitor/monitor.h"
#include "lrender.h"

#include <functional>

using namespace LGen;

const size_t Monitor::DEFAULT_WIDTH = 1024;
const size_t Monitor::DEFAULT_HEIGHT = 768;

Monitor::Monitor(const char *title) {
	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, title, NULL, NULL);
	terminate = false;

	glfwSetWindowAttrib(window, GLFW_FOCUS_ON_SHOW, GLFW_FALSE);
	glfwMakeContextCurrent(window);
	
	renderer = std::make_unique<LRender::Renderer>(DEFAULT_WIDTH, DEFAULT_HEIGHT);
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
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mousePress(LRender::Renderer::DRAG);

				break;
			case MOUSE_ACTION_DRAG_STOP:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseRelease(LRender::Renderer::DRAG);

				break;
			}

			break;
		case MOUSE_BUTTON_PAN:
			switch(action) {
			case MOUSE_ACTION_PAN_START:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mousePress(LRender::Renderer::PAN);

				break;
			case MOUSE_ACTION_PAN_STOP:
				static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseRelease(LRender::Renderer::PAN);

				break;
			}
			break;
		}
	});
}

Monitor::~Monitor() {
	glfwDestroyWindow(window);
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

void Monitor::makeVisible() const {
	if(!glfwGetWindowAttrib(window, GLFW_VISIBLE))
		glfwShowWindow(window);
}

void Monitor::enqueue(const std::shared_ptr<LRender::Renderer::Task> task) {
	renderer->enqueue(task);
}

void Monitor::poll() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}
