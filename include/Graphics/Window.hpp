//
// Created by Alexey Khazov on 11/29/2020.
//

#pragma once

#include <string>
#include <memory>
#include <GLFW/glfw3.h>

namespace Khengine::Graphics
{
	class Window
	{
	public:
		Window(std::string title, int width, int height);
		
	public:
		void Close() const;
		bool ShouldClose() const;
		
	public:
		void Resize(int width, int height);
		
	public:
		void Clear() const;
		void Update();
		
	private:
		void Init();
		
	private:
		std::string title;
		int width;
		int height;
		
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
