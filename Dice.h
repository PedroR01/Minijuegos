#pragma once
#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int id;
	int value;
	bool player;
	void diceForm();

public:
	Dice(bool whichPlayerDice);
	~Dice();

	void throw_();
	void setId(int idCounter);
	void resetValue();
	int getValue();
	int getId();
};

#endif // !DICE_H
