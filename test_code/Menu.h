#pragma once

#include "FileProc.h"

#define UP 72
#define DOWN 80
#define ENTER 13

class Menu
{
public:

	void menu();
	

private:
	uint8_t activMenu = 0;
	uint8_t ch;
	const std::string menuIteam[4] = { "Прочитать список объектов", "Добавить объект", "Группировать объекты", "Выход"};
	const std::string menuGroup[4] = { "Группировка по имени", "Группровка по типу", "Группировка по времени", "Вернуться"};
	FileProcessing fp;
	
	void groupMenu();
	
};

