#include "Games.h"
#include "TicTacToe.h"
#include "DiceGame.h"
#include <iostream>
#include <sstream>

Games::Games()
{
	currentGame = 0;
	playersBalance[0] = 0; //Player1 wins
	playersBalance[1] = 0; //Player2 wins
}

Games::~Games()
{
}

std::string Games::parseNum(int num)
{
	std::ostringstream aux;
	aux << num;

	return aux.str();
}

std::string Games::toString()
{
	return "Victorias del jugador 1: " + parseNum(1)
		+ "\nVictorias del jugador 2: " + parseNum(2);
}

void Games::initGame(int gameSelected)
{
	if (gameSelected == 1)
	{
		TicTacToe* gameT = new TicTacToe();
		currentGame = gameT;
	}
	else if (gameSelected == 2)
	{
		DiceGame* gameD = new DiceGame();
		currentGame = gameD;
	}
	/*
	else if (gameSelected == 3)
	{
		PokerGame* gameP = new PokerGame();
		currentGame = gameP;
		}
	*/
}

void Games::exitGame()
{
	// add winning/lose balance per player

	if (currentGame != NULL)
		delete currentGame;
}

std::string Games::gameInstructions(int gameSelected)
{
	if (gameSelected == 1) // Tic-Tac-Toe instructions
	{
		return "TIC-TAC-TOE\nGAME RULES: Each player will have a turn to choose which grid position to occupy. Whoever makes 3 in a line(horizontal, vertical or diagonal) wins. Enjoy :)";
	}
	else if (gameSelected == 2) // Dice instructions
	{
		return "DICE\nGAME RULES: Each player will have 3 dices (each one with his specific id to reference). The more dices match with the same number the more points you get, and if the dice has a higher value it gets you more points. Also, each player will have a second time to throw the dice/s that want. Enjoy :)";
	}
	else if (gameSelected == 3) // Poker instructions
	{
		return "POKER\nGAME RULES: Poker. Enjoy :)";
	}
	else
		return "ERROR";
}

void Games::inputValidation()
{
	int input = 0;
	do {
		std::cin >> input;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	} while (input != 1 || std::cin.fail());
}

int Games::getPlayerBalance(int player)
{
	if (player == 1)
		return playersBalance[0];
	else
		return playersBalance[1];
}