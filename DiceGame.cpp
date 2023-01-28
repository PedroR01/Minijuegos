#include "DiceGame.h"
#include <iostream>

#define DICESAMOUNT 3

DiceGame::DiceGame()
{
	gamePoints = 0;
	int diceId = 0;

	for (int i = 0; i < DICESAMOUNT; i++)
	{
		diceId++;
		playerDices.push_back(new Dice());
		playerDices.back()->setId(diceId);
	}

	printDices();
}

DiceGame::~DiceGame()
{
	std::cout << "\nQuiting Dice Game... Hope you had fun :)\nReturning to Main Menu..." << std::endl;
}

void DiceGame::reroll(int diceSelected)
{
	//playerDices[diceSelected - 1]->throw_(); // El ID es necesario a fin de cuentas?
}

void DiceGame::printDices()
{
	confirmation();

	for (int i = 0; i < DICESAMOUNT; i++)
	{
		playerDices[i]->throw_();
		//iaDices[i]->throw_();
	}

	confirmation();

	std::cin.get();
	std::cin.get();

	valueTable(gamePoints);
}

void DiceGame::confirmation()
{
	int input = 0;
	if (playerDices.empty())
	{
		do {
			std::cout << "PRESS 1 to THROW your dices" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin >> input;
		} while (input != 1 || std::cin.fail());
	}
	else
	{
		do {
			std::cout << "INTRODUCE the AMOUNT of DICE/S to REROLL some of your dices || PRESS 4 to FINISH your turn..." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin >> input;
		} while (input < 1 || input > 4 || std::cin.fail());

		if (input >= 1 && input <= 3)
		{
			int rerollTimes = input;
			do {
				std::cout << "Introduce the DICE/S to REROLL" << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cin >> input;

				if (input >= 1 && input <= 3 && input != input) // Select up to 3 dices and can´t repeat any dice already rerolled. BUG = It prevents from chossing the same dice twice, but the usar can select the same dice at the begining and at the end.
				{
					reroll(input);
					rerollTimes--;
				}
			} while (rerollTimes != 0 || std::cin.fail());
		}
	}

	std::cin.get();
	std::cin.get();
}

// attribute that stores points. This method changes that attribute. If the attribute ends with a negative value it means that the player1 lost, if it ends positive it means he wins and if it ends in 0 it means a draw.
void DiceGame::valueTable(int& totalPoints)
{
	int diceValue[DICESAMOUNT];
	int pointsCounter = 0;

	for (int i = 0; i < DICESAMOUNT; i++)
	{
		diceValue[i] = playerDices[i]->getValue();
		if (i != DICESAMOUNT)
		{
			if (diceValue[i] == diceValue[i + 1])
				pointsCounter += 5;
		}
		else {
			if (diceValue[i] == diceValue[0]) // Check if the last dice value is the same as the first one. This could be done with a list too.
				pointsCounter += 5;
		}

		switch (diceValue[i])
		{
		case 1: pointsCounter += 1;
			break;
		case 2: pointsCounter += 2;
			break;
		case 3: pointsCounter += 3;
			break;
		case 4: pointsCounter += 4;
			break;
		case 5: pointsCounter += 5;
			break;
		case 6: pointsCounter += 6;
			break;
		}
	}

	totalPoints = pointsCounter;
}