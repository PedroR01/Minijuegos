#include "Games.h"
#include "TicTacToe.h"
#include "DiceGame.h"
#include <iostream>
#include <sstream>

Games::Games()
{
	currentGame = 0;
}

Games::~Games()
{
}

int Games::balance()
{
	return 1;
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
		return "DICE\nGAME RULES: Dice. Enjoy :)";
	}
	else if (gameSelected == 3) // Poker instructions
	{
		return "POKER\nGAME RULES: Poker. Enjoy :)";
	}
	else
		return "ERROR";
}