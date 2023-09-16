#include <windows.h>
#include "Menu.h"



int main()
{	
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;
	menu.menu();

	return 0;
}