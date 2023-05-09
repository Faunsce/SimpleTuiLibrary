#include <thread>
#include <chrono>
#include <iostream>

#include "Tui.hpp"

// This exists solely to test the library

int main()
{
	setlocale(LC_ALL, "en-US");
	swt::Window window(50, 50);
	window.modifyInfo(L"bongus");
	while (true)
	{
		window.updateScreen();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
	}
}