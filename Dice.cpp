#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Dice::Dice()
{
	id = 0;
	value = 0;

	srand(time(0)); // Posible perdida de datos? Otra manera de instanciar la semilla?
}

Dice::~Dice()
{
}

void Dice::throw_()
{
	value = rand() % 6;
	diceForm();
}

void Dice::diceForm()
{
	std::cout << "Player 1..." << std::endl;
	//std::cout << "\n     |     |     " << std::endl;
	//std::cout << "  " << pos[0][0] << "  |  " << pos[0][1] << "  |  " << pos[0][2] << std::endl;
	std::cout << "   ___________ " << std::endl;
	std::cout << "  |           |    " << std::endl;
	//std::cout << "  " << pos[1][0] << "  |  " << pos[1][1] << "  |  " << pos[1][2] << std::endl;
	std::cout << "  |           |    " << std::endl;
	std::cout << "  |     " << this->value << "     |" << std::endl;
	std::cout << "  |           |    " << std::endl;
	std::cout << "  |           |    " << std::endl;
	std::cout << "  -------------" << std::endl;
	//std::cout << "_______________" << std::endl;
	//std::cout << "     |     |     " << std::endl;
	//std::cout << "  " << pos[2][0] << "  |  " << pos[2][1] << "  |  " << pos[2][2] << std::endl;
	//std::cout << "     |     |     " << std::endl;
}

void Dice::setId(int idCounter)
{
	id = idCounter;
}

int Dice::getValue()
{
	return value;
}

int Dice::getId()
{
	return id;
}