#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/Window.hpp"

int main()
{
	if(!glfwInit())
	{
		std::cout << "Error initializing GLFW!" << '\n';
		return 1;
	}
	
	if(!glewInit())
	{
		std::cout << "Error initializing GLEW" << '\n';
		return 2;
	}
	
	Khengine::Graphics::Window window("Simple Game", 1280, 720);
	
	while(!window.ShouldClose())
	{
		window.Clear();
		window.Update();
	}
	
	glfwTerminate();
	return 0;
}
