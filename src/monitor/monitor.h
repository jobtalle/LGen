#pragma once

#include <string>
#include <thread>
#include <memory>
#include <atomic>
#include <lrender.h>

#include "monitor/glfwLoader.h"

namespace LGen {
	class Monitor final {
	public:
		Monitor(const char *title);
		~Monitor();
		void start();
		void stop();
		void makeVisible() const;
		void enqueue(const std::shared_ptr<LRender::Renderer::Task> task);

	private:
		static const size_t DEFAULT_WIDTH;
		static const size_t DEFAULT_HEIGHT;
		static const int MOUSE_BUTTON_DRAG = GLFW_MOUSE_BUTTON_LEFT;
		static const int MOUSE_BUTTON_PAN = GLFW_MOUSE_BUTTON_RIGHT;
		static const int MOUSE_ACTION_DRAG_START = GLFW_PRESS;
		static const int MOUSE_ACTION_DRAG_STOP = GLFW_RELEASE;
		static const int MOUSE_ACTION_PAN_START = MOUSE_ACTION_DRAG_START;
		static const int MOUSE_ACTION_PAN_STOP = MOUSE_ACTION_DRAG_STOP;
		static const int KEY_CENTER_VIEW = GLFW_KEY_C;
		static const int KEY_FOCUS_AGENT = GLFW_KEY_F;

		void poll();

		GLFWLoader glfwLoader;
		std::unique_ptr<LRender::Renderer> renderer;
		std::atomic<bool> terminate;
	};
}