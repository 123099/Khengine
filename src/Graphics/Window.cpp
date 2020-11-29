//
// Created by Alexey Khazov on 11/29/2020.
//

#include <iostream>
#include "Graphics/Window.hpp"

namespace Khengine::Graphics
{
	// Callbacks
	void OnFrameBufferResized(GLFWwindow* windowHandle, int width, int height);
	
	Window::Window(std::string title, int width, int height) :
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
		
		// Set up callbacks
		glfwSetWindowUserPointer(windowHandle.get(), this);
		glfwSetFramebufferSizeCallback(windowHandle.get(), &OnFrameBufferResized);
	}
	
	void Window::Close() const
	{
		glfwSetWindowShouldClose(windowHandle.get(), true);
	}
	
	bool Window::ShouldClose() const
	{
		return static_cast<bool>(glfwWindowShouldClose(windowHandle.get()));
	}
	
	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(windowHandle.get());
	}
	
	void Window::Resize(int width, int height)
	{
		this->width = width;
		this->height = height;
		glViewport(0, 0, width, height);
	}
	
	void OnFrameBufferResized(GLFWwindow* windowHandle, int width, int height)
	{
		Window* window = static_cast<Window*>(glfwGetWindowUserPointer(windowHandle));
		window->Resize(width, height);
	}
}