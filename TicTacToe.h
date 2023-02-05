#pragma once
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
#include "Games.h"

class TicTacToe : public Games
{
	char pos[3][3] =
	{
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};
	int choice;
	int row, column;
	int turn = 1;
	//int rematch = 1;
	bool draw = false;

	void printBoard();
	void playerTurn();
	bool gameState();
	void gameOver();
	void reset();
	std::string parseNum(int num);

public:
	TicTacToe();
	~TicTacToe();
};

#endif // !TICTACTOE_H