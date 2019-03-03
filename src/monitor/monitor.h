#pragma once

#include <string>
#include <thread>
#include <memory>
#include <atomic>
#include <lrender.h>
#include <GLFW/glfw3.h>

namespace LGen {
	class Monitor final {
	public:
		Monitor(const char *title);
		~Monitor();
		void start();
		void stop();
		void makeVisible() const;
		void enqueue(const std::shared_ptr<const LRender::Renderer::Task> task);

	private:
		static const size_t DEFAULT_WIDTH = 1024;
		static const size_t DEFAULT_HEIGHT = 768;
		static const size_t GL_VERSION_MAJOR = 4;
		static const size_t GL_VERSION_MINOR = 4;
		static const size_t MSAA_SAMPLES = 4;
		static const int MOUSE_BUTTON_DRAG = GLFW_MOUSE_BUTTON_LEFT;
		static const int MOUSE_BUTTON_PAN = GLFW_MOUSE_BUTTON_RIGHT;
		static const int MOUSE_ACTION_DRAG_START = GLFW_PRESS;
		static const int MOUSE_ACTION_DRAG_STOP = GLFW_RELEASE;
		static const int MOUSE_ACTION_PAN_START = MOUSE_ACTION_DRAG_START;
		static const int MOUSE_ACTION_PAN_STOP = MOUSE_ACTION_DRAG_STOP;

		static void glfwStart();
		static void glfwStop();

		void poll();

		GLFWwindow *window;
		std::unique_ptr<LRender::Renderer> renderer;
		std::atomic<bool> terminate;
	};
};