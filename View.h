#pragma once
#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

class Presenter;

class View : public IView
{
private:
	Presenter* m_Presenter;
	void header(std::string actualSection);
	void showMainMenu();
	void selectOption(int& input, int min, int max);
	void beginPlay(int gameSelected);

public:
	View();
	~View() override;

	void showText(const std::string& text) override;
	void showTextWithSection(const std::string& text) override;
	void showTextWithConfirmation(const std::string& text) override;
	std::string parseNum(double value) override;
};

#endif // VIEW_H
