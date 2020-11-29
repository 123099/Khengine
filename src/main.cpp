#include <iostream>
#include <GLFW/glfw3.h>
#include "Graphics/Window.hpp"

int main()
{
	int const initResult = glfwInit();
	
	if(initResult != GLFW_TRUE)
	{
		std::cout << "Error initializing GLFW!" << '\n';
	}
	else
	{
		std::cout << "Init successful!" << '\n';
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
