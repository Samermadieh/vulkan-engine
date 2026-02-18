#include "lve_window.hpp"

#include <stdexcept>

namespace lve {
	LveWindow::LveWindow(int w, int h, std::string windowName) : width{ w }, height{ h }, name{ windowName } {
		init();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::init() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Disable because not OpenGL
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Don't resize window

		window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create window surface.");
		}
	}
}