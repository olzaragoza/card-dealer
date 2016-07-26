/* card-dealer.cpp */

#include <iostream>
#include "Dealer.h"

int main()
{
	int runs = 0;

	Dealer play;

	play.welcome();
	play.validate(runs);
	play.deal(runs);
	play.displayTotals();

	system("pause");
	return 0;
}