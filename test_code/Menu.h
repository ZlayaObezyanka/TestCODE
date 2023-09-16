#pragma once

#include "FileProc.h"

#define UP 72
#define DOWN 80
#define ENTER 13

class Menu
{
public:

	void menu()
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
					std::cout << "������� ����� ������� ��� �����������" << '\n';
					_getch();
				}
				else if (activMenu == 1)
				{
					system("CLS");
					fp.writeToFile();
					std::cout << "������� ����� ������� ��� �����������" << '\n';
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

private:
	uint8_t activMenu = 0;
	uint8_t ch;
	const std::string menuIteam[4] = { "��������� ������ ��������", "�������� ������", "������������ �������", "�����"};
	const std::string menuGroup[4] = { "����������� �� �����", "���������� �� ����", "����������� �� �������", "���������"};
	FileProcessing fp;
	
	void groupMenu()
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
					std::cout << "������� ����� ������� ��� �����������";
					_getch();
				}
				else if (activMenu == 1)
				{
					fp.groupBy_Type();
					std::cout << "������� ����� ������� ��� �����������";
					_getch();
				}
				else if (activMenu == 2)
				{
					fp.groupByTime();
					std::cout << "������� ����� ������� ��� �����������";
					_getch();
				}
				else
					return;
				system("CLS");
			}
			}

		}
	}
};

