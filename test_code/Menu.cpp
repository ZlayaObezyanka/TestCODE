#include "Menu.h"

#include <iostream>
#include <conio.h>

static constexpr int UP = 72;
static constexpr int DOWN = 80;
static constexpr int ENTER = 13;


void Menu::menu()
{
	while (true) {
		system("CLS");
		for (int i = 0; i < size(menuIteam); ++i)
		{
			i == activMenu ? std::cout << '>' << menuIteam[i] << '<' << '\n' : std::cout << ' ' << menuIteam[i] << ' ' << '\n';
		}

		ch = _getch();
		switch (ch)
		{
		case UP:
		{
			if (activMenu > 0)
				--activMenu;
			break;
		}
		case DOWN:
		{
			if (activMenu < size(menuIteam) - 1)
				++activMenu;
			break;
		}
		case ENTER:
		{
			if (activMenu == 0)
			{
				system("CLS");
				fp.readFile("test.txt");
				std::cout << "Введите любой символ с клавиатуры для продолжения" << '\n';
				_getch();
			}
			else if (activMenu == 1)
			{
				system("CLS");
				fp.writeToFile();
				std::cout << "Введите любой символ с клавиатуры для продолжения" << '\n';
				_getch();
			}
			else if (activMenu == 2)
			{
				groupMenu();
				break;
			}
			else
				return;
		}
		}
	}
}

void Menu::groupMenu()
{
	activMenu = 0;
	while (true)
	{
		system("CLS");
		for (int i = 0; i < size(menuGroup); ++i)
		{
			i == activMenu ? std::cout << '>' << menuGroup[i] << '<' << '\n' : std::cout << ' ' << menuGroup[i] << ' ' << '\n';
		}

		ch = _getch();
		switch (ch)
		{
		case UP:
		{
			if (activMenu > 0)
				--activMenu;
			break;
		}
		case DOWN:
		{
			if (activMenu < size(menuIteam) - 1)
				++activMenu;
			break;
		}
		case ENTER:
		{
			if (activMenu == 0)
			{
				system("CLS");
				fp.groupByName();
				std::cout << "Введите любой символ с клавиатуры для продолжения";
				_getch();
			}
			else if (activMenu == 1)
			{
				system("CLS");
				fp.groupBy_Type();
				std::cout << "Введите любой символ с клавиатуры для продолжения";
				_getch();
			}
			else if (activMenu == 2)
			{
				system("CLS");
				fp.groupByTime();
				std::cout << "Введите любой символ с клавиатуры для продолжения";
				_getch();
			}
			else
				return;
			system("CLS");
		}
		}
	}
}
