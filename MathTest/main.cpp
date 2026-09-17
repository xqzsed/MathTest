#include <iostream>
#include <windows.h>
#include "lib.h"

int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	MathTest Test(5, -10, 50);

	Test.run();

	Test.showStatistics();

	return 0;
}