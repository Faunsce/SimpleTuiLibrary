#include "Tui.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace swt
{
	Window::Window(int displayWidth, int displayHeight)
	{
		this->elementGrid = Window::charGrid(displayHeight, Window::charVector(displayWidth, L' '));
	}

	Window::~Window()
	{

	}

	void Window::updateScreen()
	{
		this->clearScreen();
		Window::charGrid data = this->elementGrid;

		this->addBorders(data);

		for (const auto& line : data)
		{
			for (const auto& element : line)
			{
				std::wcout << element;
			}
			std::wcout << L'\n';
		}
	}
	
	void Window::addBorders(Window::charGrid& grid)
	{
		grid.insert(grid.begin(), Window::charVector(grid[0].size(), L'═'));
		grid.emplace_back(Window::charVector(grid[0].size(), L'═'));

		for (auto& row : grid)
		{
			row.insert(row.begin(), L'═');
			row.emplace_back(L'═');
		}

		grid.front().front() = L'╔';
		grid.front().back() = L'╗';
		grid.back().front() = L'╚';
		grid.back().back() = L'╝';
	}

	void Window::modifyInfo(std::wstring message)
	{
		for (auto& row : this->elementGrid)
		{
			for (auto& element : row)
			{
				if (message.empty())
				{
					return;
				}
				element = message.back();
				message.pop_back();
			}
		}
	}

	void Window::

}