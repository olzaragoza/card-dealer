#pragma once

class Dealer
{
private:
	int hearts = 0;
	int clubs = 0;
	int diamonds = 0;
	int spades = 0;

	int heartsTotal = 0;
	int clubsTotal = 0;
	int diamondsTotal = 0;
	int spadesTotal = 0;

	int deals = 0;
	int cardNumber = 0;
	int runTimes = 0;
	int runCount = 0;

public:
	Dealer();
	~Dealer();

	void welcome();
	void validate(int &n);
	void randomCard();
	void deal(int &r);
	void display();
	void displayTotals();
};