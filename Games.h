#pragma once
#ifndef GAMES_H
#define GAMES_H
#include <string>

class Games
{
private:
	Games* currentGame;

protected:
	int balance();
	std::string parseNum(int num);
	std::string toString();
	void exitGame();
public:
	Games();
	~Games();

	void initGame(int gameSelected);
	std::string gameInstructions(int gameSelected);
};

#endif // !GAMES_H
