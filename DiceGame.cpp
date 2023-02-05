#include "DiceGame.h"
#include <iostream>
#include <string>
#include <sstream>

#define DICESAMOUNT 3

DiceGame::DiceGame()
{
	rematch = 1;
	playerTurn = 1;
	gamePoints = 0;
	int diceId = 0;

	for (int i = 0; i < DICESAMOUNT; i++)
	{
		diceId++;
		playerDices.push_back(new Dice(true));
		playerDices.back()->setId(diceId);
	}

	diceId = 0;
	for (int i = 0; i < DICESAMOUNT; i++)
	{
		diceId++;
		iaDices.push_back(new Dice(false));
		iaDices.back()->setId(diceId);
	}

	turn(playerTurn);
}

DiceGame::~DiceGame()
{
	for (auto ptr : playerDices)
		delete ptr;

	for (auto iaPtr : iaDices)
		delete iaPtr;

	std::cout << "\nQuiting Dice Game... Hope you had fun :)\nReturning to Main Menu..." << std::endl;
}

void DiceGame::turn(int player)
{
	if (player == 1)
		printDices(playerDices);
	else
		printDices(iaDices);
}

void DiceGame::reroll(std::vector <Dice*> dices, int diceSelected)
{
	dices[diceSelected - 1]->throw_(); // El ID es necesario a fin de cuentas?
}

void DiceGame::printDices(std::vector <Dice*> dices)
{
	confirmation(dices);

	for (int i = 0; i < DICESAMOUNT; i++)
		dices[i]->throw_();

	confirmation(dices);

	if (iaDices.back()->getValue() == 0)
	{
		playerTurn = 2;
		turn(playerTurn);
	}

	valueTable(gamePoints);

	if (rematch != 0)
	{
		std::cout << "FINAL POINTS --> " << gamePoints << std::endl;
		if (gamePoints > 0)
		{
			std::cout << "PLAYER 1 WINS" << std::endl;
			playersBalance[0] ++;
		}
		else if (gamePoints < 0)
		{
			std::cout << "PLAYER 2 WINS" << std::endl;
			playersBalance[1] ++;
		}
		else if (gamePoints == 0)
			std::cout << "EPIC DRAW" << std::endl;

		playerTurn = 1;

		std::cout << "Want a rematch? (0 = EXIT): ";
		std::cin >> rematch;

		if (rematch != 0) // HOTFIX. WORKS FOR NOW BUT ITS NOT OPTIMAL
		{
			for (auto ptr : playerDices)
				ptr->resetValue();

			for (auto iaPtr : iaDices)
				iaPtr->resetValue();

			gamePoints = 0;
			turn(playerTurn);
		}
	}
	else
		exitGame();
}

void DiceGame::confirmation(std::vector <Dice*> dices)
{
	// FIRST TIME THROWING DICES
	int input = 0;
	if (dices.back()->getValue() == 0)
	{
		do {
			std::cout << "PRESS 1 to THROW your dices (PLAYER " << playerTurn << ")." << std::endl;
			std::cin >> input;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		} while (input != 1 || std::cin.fail());
	}
	// REROLL TIME
	else
	{
		std::string idInput;
		bool wrongInput = false;
		do {
			std::cout << "\n";
			std::cout << "         -------------------------------------            " << std::endl;
			std::cout << "           INTRODUCE THE DICE/S ID TO REROLL              " << std::endl;
			std::cout << "Introduce digit/s with space between (Input example -->1 2 3) " << std::endl;
			std::getline(std::cin, idInput);
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			if (idInput.empty())
				return;

			for (int i = 0; i < idInput.length(); i++) // Prevents ERRORS with invalid inputs
			{
				if (isalpha(idInput[i]) || isspace(idInput[i]) && isspace(idInput[i + 1]))
					wrongInput = true;
			}
		} while (wrongInput);

		std::istringstream dicesId(idInput);
		int id[DICESAMOUNT];
		int amountOfDices = 0;

		while (dicesId >> id[amountOfDices])
		{
			if (amountOfDices < DICESAMOUNT)
				amountOfDices++;
		}

		for (int i = 0; i < amountOfDices; i++)
			reroll(dices, id[i]);
	}
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

	for (int i = 0; i < DICESAMOUNT; i++)
	{
		diceValue[i] = iaDices[i]->getValue();
		if (i != DICESAMOUNT)
		{
			if (diceValue[i] == diceValue[i + 1])
				pointsCounter -= 5;
		}
		else {
			if (diceValue[i] == diceValue[0]) // Check if the last dice value is the same as the first one. This could be done with a list too.
				pointsCounter -= 5;
		}

		switch (diceValue[i])
		{
		case 1: pointsCounter -= 1;
			break;
		case 2: pointsCounter -= 2;
			break;
		case 3: pointsCounter -= 3;
			break;
		case 4: pointsCounter -= 4;
			break;
		case 5: pointsCounter -= 5;
			break;
		case 6: pointsCounter -= 6;
			break;
		}
	}

	totalPoints = pointsCounter;
}