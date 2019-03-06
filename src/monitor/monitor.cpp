#include "monitor/monitor.h"
#include "lrender.h"

#include <functional>

using namespace LGen;

const size_t Monitor::DEFAULT_WIDTH = 1024;
const size_t Monitor::DEFAULT_HEIGHT = 768;

Monitor::Monitor(const char *title) :
	glfwLoader(DEFAULT_WIDTH, DEFAULT_HEIGHT, title) {
	terminate = false;
	
	renderer = std::make_unique<LRender::Renderer>(DEFAULT_WIDTH, DEFAULT_HEIGHT);
	glfwSetWindowUserPointer(glfwLoader.getWindow(), renderer.get());

	glfwSetWindowSizeCallback(glfwLoader.getWindow(), [](GLFWwindow *window, int width, int height) {
		static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->setSize(width, height);
	});

	glfwSetCursorPosCallback(glfwLoader.getWindow(), [](GLFWwindow *window, double x, double y) {
		static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->mouseMove(x, y);
	});

	glfwSetScrollCallback(glfwLoader.getWindow(), [](GLFWwindow *window, double dx, double dy) {
		if(dy > 0)
			static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->scrollUp();
		else
			static_cast<LRender::Renderer*>(glfwGetWindowUserPointer(window))->scrollDown();
	});

	glfwSetMouseButtonCallback(glfwLoader.getWindow(), [](GLFWwindow *window, int button, int action, int mods) {
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

void Monitor::start() {
	while(!terminate) {
		poll();

		if(glfwWindowShouldClose(glfwLoader.getWindow())) {
			glfwHideWindow(glfwLoader.getWindow());
			glfwSetWindowShouldClose(glfwLoader.getWindow(), GLFW_FALSE);
		}

		glfwLoader.makeCurrent();
		renderer->update();

		if(glfwGetWindowAttrib(glfwLoader.getWindow(), GLFW_VISIBLE))
			renderer->render();
	}
}

void Monitor::stop() {
	terminate = true;
}

void Monitor::makeVisible() const {
	if(!glfwGetWindowAttrib(glfwLoader.getWindow(), GLFW_VISIBLE))
		glfwShowWindow(glfwLoader.getWindow());
}

void Monitor::enqueue(const std::shared_ptr<LRender::Renderer::Task> task) {
	renderer->enqueue(task);
}

void Monitor::poll() {
	glfwSwapBuffers(glfwLoader.getWindow());
	glfwPollEvents();
}
