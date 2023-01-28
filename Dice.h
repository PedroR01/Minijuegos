#pragma once
#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int id;
	int value;
	void diceForm();

public:
	Dice();
	~Dice();

	void throw_();
	void setId(int idCounter);
	int getValue();
	int getId();
};

#endif // !DICE_H
