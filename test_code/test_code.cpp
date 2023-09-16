// test_code.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
//#include <list>
#include <vector>

#include <conio.h>
#include "Menu.h"



int main()
{
	setlocale(LC_ALL, "rus");
	Menu menu;
	menu.menu();
}