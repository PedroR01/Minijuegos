#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();
	void GameSelection();
	std::string toString();
private:
	int option;
};

#endif // !MENU_H