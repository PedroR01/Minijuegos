#include "Presenter.h"
#include "IView.h"
#include "Games.h"
#include <iostream>

Presenter::Presenter(IView* view) : m_View(view), m_Game(new Games())
{
}

Presenter::~Presenter()
{
	delete m_Game;
}

void Presenter::sendGameSelected(int gameSelected)
{
	m_Game->initGame(gameSelected);
}

std::string Presenter::showInstructions(int gameSelected)
{
	return m_Game->gameInstructions(gameSelected);
}