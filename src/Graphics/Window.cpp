//
// Created by Alexey Khazov on 11/29/2020.
//

#include <iostream>
#include "Graphics/Window.hpp"

namespace Khengine::Graphics
{
	Window::Window(std::string title, uint32_t width, uint32_t height) :
		title(std::move(title)),
		width(width),
		height(height)
	{
		Init();
	}
	
	void Window::Init()
	{
		// Create window and wrap in unique_ptr
		windowHandle.reset(glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr));
		
		if(windowHandle == nullptr)
		{
			std::cout << "Failed to create window!" << '\n';
			return;
		}
		
		// Set the current OpenGL context
		glfwMakeContextCurrent(windowHandle.get());
	}
	
	void Window::Close()
	{
		glfwSetWindowShouldClose(windowHandle.get(), true);
	}
	
	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(windowHandle.get());
	}
	
	void Window::Update() const
	{
		glfwPollEvents();
		glfwSwapBuffers(windowHandle.get());
	}
}