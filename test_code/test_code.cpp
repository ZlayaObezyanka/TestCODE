// test_code.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <algorithm>
#include <fstream>
//#include <string>
//#include <iterator>
#include <vector>
#include <conio.h>
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