#pragma once
#ifndef GAMES_H
#define GAMES_H
#include <string>

class Games
{
private:
	Games* currentGame;

protected:
	int rematch = 1;
	int playersBalance[2];
	std::string parseNum(int num);
	std::string toString();
	void exitGame();
	void inputValidation();
public:
	Games();
	~Games();

	void initGame(int gameSelected);
	std::string gameInstructions(int gameSelected);
	int getPlayerBalance(int player);
};

#endif // !GAMES_H
