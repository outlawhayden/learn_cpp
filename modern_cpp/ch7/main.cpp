#include <iostream>
#include <random>

#include "input.h"
#include "analysis.h"

void random_experiment()
{
	std::random_device rd{}; // make a random_device to generate a seed
	std::default_random_engine generator(rd()); // makes an engine using random seed
	std::uniform_int_distribution distribution{-1,1}; // make a distribution between 1,6 uniform
	const int roll = distribution(generator); //get random int from distribution with sample from generator
	std::cout << "Dice roll " << roll << "\n"; // print output
}

void trading_game()
{
	const double start_price = 100.0;
	std::cout << "Stock bought for: " << start_price << "\n";

	auto prices = stock_prices::get_prices(start_price, 10);
	for(auto price : prices)
	{
		std::cout << "Current price: " << price << '\n';
		std::cout << "Press (s) to sell\n>";
		char choice{};
		std::cin >> choice;

		if (choice == 's')
		{
			const double profit = price - start_price;
			std::cout << "Profit " << profit << "\n";
			break;
		}
	}
	std::cout << "Game over\n";
}

int main()
{
	random_experiment();
	stock_prices::test_input();
	//const auto prices = stock_prices::get_prices(100.0, 10);
	const auto prices = stock_prices::get_prices(100.0, 10, 0.05);
	std::cout << "Got prices.\n";

	for(double p : prices)
	{
		std::cout << p << '\n';
	}

	const auto profit = stock_prices::profit_on_first_uptick(prices);
	std::cout << "Profit " << profit << "\n";

	std::random_device rd{};
	std::default_random_engine gen{rd()};
	std::normal_distribution distrib;

	double price = 100.0;
	const double volatility = 0.05;

	auto next_price = [volatility, &price, &gen, &distrib]()
	{
		double percent = volatility * distrib(gen);
		price += price * percent;
		return price;
	};

	const auto more_prices = stock_prices::get_prices(100.0, 10, next_price);
	trading_game();
}
