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

		
		data.insert(data.begin(), Window::charVector(data[0].size(), L'═'));
		data.emplace_back(Window::charVector(data[0].size(), L'═'));

		for (auto& row : data)
		{
			row.insert(row.begin(), L'═');
			row.emplace_back(L'═');
		}

		data.front().front() = L'╔';
		data.front().back() = L'╗';
		data.back().front() = L'╚';
		data.back().back() = L'╝';

		for (const auto& line : data)
		{
			for (const auto& element : line)
			{
				std::wcout << element;
			}
			std::wcout << L'\n';
		}
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

}