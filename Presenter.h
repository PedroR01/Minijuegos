#pragma once
#ifndef PRESENTER_H
#define PRESENTER_H
#include <string>

class IView;
class Games;

class Presenter
{
private:
	IView* m_View = nullptr;

public:
	Games* m_Game;

	explicit Presenter(IView* view);
	~Presenter();

	void sendGameSelected(int gameSelected);

	std::string showInstructions(int gameSelected);
	int showPlayersBalance(int player);
};

#endif // !PRESENTER_H
