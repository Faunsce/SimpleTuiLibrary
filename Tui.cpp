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

		for (const auto& line : this->displayGrid)
		{
			for (const auto& element : line)
			{
				std::wcout << element;
			}
			std::wcout << L'\n';
		}
	}
	
	Window::charGrid Window::addBorders(Window::charGrid grid)
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

		return grid;
	}

	void Window::modifyInfo(std::wstring message)
	{
		for (auto& row : this->elementGrid)
		{
			for (auto& element : row)
			{
				if (message.empty())
				{
					this->displayGrid = this->addBorders(this->elementGrid);
					return;
				}
				element = message.front();
				message.erase(message.begin());
				message.shrink_to_fit();
			}
		}		
	}
}