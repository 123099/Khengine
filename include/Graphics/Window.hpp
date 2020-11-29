//
// Created by Alexey Khazov on 11/29/2020.
//

#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <GLFW/glfw3.h>

namespace Khengine::Graphics
{
	class Window
	{
	public:
		Window(std::string title, uint32_t width, uint32_t height);
		
	public:
		void Close();
		bool ShouldClose() const;
		
	public:
		void Update() const;
		
	private:
		void Init();
		
	private:
		std::string title;
		uint32_t width;
		uint32_t height;
		
	private:
		struct GLFWwindowDeleter
		{
			void operator()(GLFWwindow* windowHandle)
			{
				glfwDestroyWindow(windowHandle);
			}
		};
		
		std::unique_ptr<GLFWwindow, GLFWwindowDeleter> windowHandle;
	};
}
