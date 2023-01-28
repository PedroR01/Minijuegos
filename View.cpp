#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <sstream>

#define SECTION "---------------------------------------"
#define INT_MAX 2147483647
#define ERROR "Invalid input, please try again following the instructions..."

View::View()
{
	m_Presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
}

void View::header(std::string actualSection)
{
	system("CLS");

	showTextWithSection("\nMINIGAMES  - " + actualSection);
	if (actualSection == "Main Menu")
	{
	}
	else
	{
		showText(SECTION);
		showTextWithSection("Press 4 to return to Main Menu");
	}
}

void View::showMainMenu()
{
	header("Main Menu");

	showTextWithSection("\nPLEASE SELECT THE GAME YOU WANT TO PLAY:");
	showText("1) Tic-Tac-Toe");
	showText("2) Dices");
	showText("3) Poker");
	showTextWithSection("4) Exit");

	int choice = 1;
	selectOption(choice, 1, 4);

	if (choice >= 1 && choice < 3) // When other games are finished, change this condition for choice >= 1 && choice < 4
	{
		system("CLS");
		beginPlay(choice);
	}
	else if (choice == 3)
	{
		showTextWithSection("Not avaible... We are working to bring you Poker in short time.");
		std::cin.get();
		std::cin.get();
	}
	else if (choice == 4)
		exit(0);

	showMainMenu(); // Return to the menu when the user exits the current game (instance of the game is deleted)
}

void View::selectOption(int& input, int min, int max) // Allows the user to enter an input and check if its valid.
{
	bool mainMenu = false;
	if (input == 1) // If the input is initialized with 1, this means that is being called from the mainMenu.
		mainMenu = true;

	do
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n'); // This prevents the user from enter any other type of value that is not int, but to work needs to enter the value 2 times.
		std::cin >> input;
		if (input  < min || input > max)
			showTextWithSection(ERROR);
	} while (input < min || input > max && max != 0 || std::cin.fail());

	if (input == max && !mainMenu) // This way the max value of the main menu allows to quit the app.
		showMainMenu();
}

void View::beginPlay(int gameSelected)
{
	showTextWithConfirmation(m_Presenter->showInstructions(gameSelected));
	system("CLS");

	m_Presenter->sendGameSelected(gameSelected);
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}
void View::showTextWithSection(const std::string& text)
{
	std::cout << text << std::endl;
	std::cout << SECTION << std::endl;
}

void View::showTextWithConfirmation(const std::string& text)
{
	int confirm = 0;
	std::cout << text << std::endl;
	std::cout << SECTION << std::endl;
	std::cout << "1) Start playing" << std::endl;
	std::cout << "2) Go back to Main Menu" << std::endl;
	std::cout << SECTION << std::endl;
	selectOption(confirm, 1, 2);
}

std::string View::parseNum(double value)
{
	std::ostringstream aux;
	aux << value; // Take the values of variable value and it change them into a char array
	return aux.str(); // Transforms the char array into a string and returns it
}