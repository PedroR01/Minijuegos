#pragma once
#ifndef DICEGAME_H
#define DICEGAME_H
#include <vector>
#include "Games.h"
#include "Dice.h"

class DiceGame : public Games
{
private:
	int gamePoints;

public:

	std::vector <Dice*> playerDices;
	std::vector <Dice*> iaDices;

	DiceGame();
	~DiceGame();

	void reroll(int diceSelected);
	void printDices();
	void valueTable(int& totalPoints);
	void confirmation();
};

#endif // !DICEGAME_H
