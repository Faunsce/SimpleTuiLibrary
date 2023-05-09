#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace swt
{

	class Window
	{
	private:
		typedef std::vector<wchar_t> charVector;
		typedef std::vector<Window::charVector> charGrid;
		Window::charGrid elementGrid;

	public:
		Window(int displayWidth, int displayHeight);
		~Window();
		void updateScreen();
		void modifyInfo(std::wstring message);
	private:
		void addBorders(Window::charGrid& grid);
		void clearScreen() {std::wcout << L"\x1b[2J\x1b[H";};
	};
}


/*
Tui Library

Functionality

Output
- Created fixed display window
- Be able to pass it custom "message" format for display
- Provide Left/Right/Middle "centering"
- Provide functionality to determine spacing ratios between sections of display'd elements
- Be able to display simple data sets (vectors of int/char/float)
- Allow user input to be filtered into display
*/

/*
╔═╗
║ ║
╚═╝
*/