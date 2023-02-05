#include "TicTacToe.h"
#include <iostream>
#include <sstream>

using namespace std;

TicTacToe::TicTacToe()
{
	printBoard();
	playerTurn();
}

TicTacToe::~TicTacToe()
{
}

void TicTacToe::printBoard()
{
	cout << "Player 1 (X) ----- Player 2 (O)" << endl;
	cout << "\n     |     |     " << endl;
	cout << "  " << pos[0][0] << "  |  " << pos[0][1] << "  |  " << pos[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << pos[1][0] << "  |  " << pos[1][1] << "  |  " << pos[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << pos[2][0] << "  |  " << pos[2][1] << "  |  " << pos[2][2] << endl;
	cout << "     |     |     " << endl;
}

void TicTacToe::playerTurn()
{
	while (!gameState())
	{
		if (turn == 1)
			cout << "Player 1 (X) turn. Enter position to draw: ";
		else
			cout << "Player 2 (O) turn. Enter position to draw: ";

		cin >> choice;

		switch (choice)
		{
		case 1: row = 0; column = 0;
			break;
		case 2: row = 0; column = 1;
			break;
		case 3: row = 0; column = 2;
			break;
		case 4: row = 1; column = 0;
			break;
		case 5: row = 1; column = 1;
			break;
		case 6: row = 1; column = 2;
			break;
		case 7: row = 2; column = 0;
			break;
		case 8: row = 2; column = 1;
			break;
		case 9: row = 2; column = 2;
			break;
		default: cout << "Invalid position" << endl;
		}

		// Player 1 drawing if the box is not used
		if (turn == 1 && pos[row][column] != 'X' && pos[row][column] != 'O') {
			pos[row][column] = 'X';
			turn = 2;
		}
		// Player 2 drawing if the box is not used
		else if (turn == 2 && pos[row][column] != 'X' && pos[row][column] != 'O') {
			pos[row][column] = 'O';
			turn = 1;
		}
		else //if the box is already used
		{
			cout << "Box already used! Introduce a valid position" << endl;
			playerTurn();
		}

		// Board updating after changes
		printBoard();
		playerTurn();
		gameState();
	}

	if (rematch != 0)
		gameOver();
}

bool TicTacToe::gameState() {
	// checking the win for simple rows and simple columns
	for (int i = 0; i < 3; i++)
	{
		if (pos[i][0] == pos[i][1] && pos[i][0] == pos[i][2] || pos[0][i] == pos[1][i] && pos[0][i] == pos[2][i])
			return true;
	}

	// checking the win for both diagonal
	if (pos[0][0] == pos[1][1] && pos[0][0] == pos[2][2] || pos[0][2] == pos[1][1] && pos[0][2] == pos[2][0])
		return true;

	// cheking for a remaining slot
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (pos[i][j] != 'X' && pos[i][j] != 'O')
				return false;
		}
	}

	// if anyone won is a draw
	draw = true;
	return true;
}

void TicTacToe::gameOver()
{ // the number turn are inversed for the check because they change turn before winning
	if (turn == 2 && draw == false)
	{
		cout << "\nCongratulations! Player 1 (X) has won the game" << endl;
		playersBalance[0] ++;
	}
	else if (turn == 1 && draw == false)
	{
		cout << "\nCongratulations! Player 2 (O) has won the game" << endl;
		playersBalance[1] ++;
	}
	else
		cout << "\nGAME DRAW!" << endl;

	cout << "Want a rematch? (0 = EXIT): ";
	cin >> rematch;

	if (rematch != 0)
		reset();
	else
		exitGame();
}

void TicTacToe::reset()
{
	int contador = 0;
	draw = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			contador++;
			pos[i][j] = parseNum(contador)[0];
		}
	}
	turn = 1;
	choice = NULL;
	printBoard();
	playerTurn();
}

string TicTacToe::parseNum(int num)
{
	ostringstream aux;
	aux << num;

	return aux.str();
}