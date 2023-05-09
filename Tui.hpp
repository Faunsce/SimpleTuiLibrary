#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace swt
{

	class Window
	{
	private:
		int displayX;
		int displayY;
		std::vector <std::vector<wchar_t>> displayWindow;
		std::wstring displayData;
	public:
		Window(std::pair<int, int> dimensions);
		~Window();
		void updateScreen();
		void modifyInfo(std::wstring message);
	private:
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