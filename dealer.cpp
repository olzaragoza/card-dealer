#include <iostream>
#include <time.h>
#include "Dealer.h"

Dealer::Dealer()
{
	// static cast used to prevent possible loss of data warning
	int seed = static_cast<int> (time(nullptr));
	srand(seed);
}

void Dealer::welcome()
{
	std::cout
		<< "*********    Welcome to the Card Dealing Simulator    *********\n"
		<< "  Simulate dealing a single card from a deck 1000 times,\n"
		<< "  then display how many times each suit gets dealt.\n"
		<< "  How many runs (of 1000 deals) would you like to perform? ";
}

void Dealer::validate(int &n)
{
	std::cin >> n;
	std::cout << "\n";

	while (!std::cin || n < 1)
	{
		std::cin.sync();
		std::cin.clear();
		std::cin.ignore();
		system("cls");
		std::cout << "Invalid entry, please try again.\n\n";
		welcome();
		std::cin >> n;
	}
}
void Dealer::randomCard()
{
	if (cardNumber <= 13)
		clubs++;
	else {
		if (cardNumber <= 26)
			diamonds++;
		else {
			if (cardNumber <= 39)
				hearts++;
			else
				spades++;
		}
	}
}

void Dealer::deal(int &r)
{
	runTimes = r;
	int total = runTimes * 1000;
	int count = 0;

	while ( (deals < total) && (runCount <= runTimes) )
	{
		cardNumber = rand() % 52 + 1;

		randomCard();
		deals = deals + 1;
		count++;

		runCount = count / 1000;

		if (count % 1000 == 0) {
			display();
			heartsTotal = heartsTotal + hearts;
			clubsTotal = clubsTotal + clubs;
			diamondsTotal = diamondsTotal + diamonds;
			spadesTotal = spadesTotal + spades;
			hearts = clubs = diamonds =	spades = 0;
		}
	}
}

void Dealer::display()
{
	std::cout << "Run #" << runCount << ":  Hearts = " << hearts << ", Clubs = " << clubs
		<< ", Diamonds = " << diamonds << ", Spades = " << spades  << std::endl;
}

void Dealer::displayTotals()
{
	if (runTimes > 1) {
		std::cout << "\nTotals after " << runTimes << " runs:"
			<< "\nHearts = " << heartsTotal
			<< ", Clubs = " << clubsTotal
			<< ", Diamonds = " << diamondsTotal
			<< ", Spades = " << spadesTotal
			<< "\n\n";
	}
	else { std::cout << "\n"; }
}