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
		void setScene(std::shared_ptr<LRender::Scene> scene);

	private:
		static const size_t DEFAULT_WIDTH;
		static const size_t DEFAULT_HEIGHT;
		static const size_t GL_VERSION_MAJOR;
		static const size_t GL_VERSION_MINOR;
		static const int MOUSE_BUTTON_DRAG = GLFW_MOUSE_BUTTON_LEFT;
		static const int MOUSE_ACTION_DRAG_START = GLFW_PRESS;
		static const int MOUSE_ACTION_DRAG_STOP = GLFW_RELEASE;


		static void glfwStart();
		static void glfwStop();

		void poll();

		GLFWwindow *window;
		std::unique_ptr<LRender::Renderer> renderer;
		std::atomic<bool> terminate;
	};
};