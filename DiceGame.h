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

	void turn(int player);
	void reroll(std::vector <Dice*> dices, int diceSelected);
	void printDices(std::vector <Dice*> dices);
	void valueTable(int& totalPoints);
	void confirmation(std::vector <Dice*> dices);
};

#endif // !DICEGAME_H
