#include "Tui.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace swt
{
	Window::Window(std::pair<int, int> dimensions)
	{
		this->displayX = dimensions.first;
		this->displayY = dimensions.second;
	}

	Window::~Window()
	{

	}

	void Window::updateScreen()
	{
		this->clearScreen();
		std::wcout << this->displayData;
	}

	void Window::modifyInfo(std::wstring message)
	{
		this->displayData = message;
	}

}