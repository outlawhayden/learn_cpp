#include<algorithm>
#include<iostream>
#include<vector>
#include<ranges>

#include "input.h"
#include "analysis.h"

int main()
{
	stock_prices::test_input();

	std::cout << "Please enter some numbers.\n";
	auto prompt = [] () {std::cout << '>';};
	auto prices = stock_prices::get_prices(std::cin, prompt);
	std::cout << "Got " << prices.size() << " price(s) \n";

	std::cout << "The following are valid:\n";
	auto valid_prices = std::views::filter(prices, [](double p) {return p >= 0.0;} );

	for (double price : valid_prices)
	{
			std::cout << price << '\n';
	}

	const auto valid_prices_as_vector = std::ranges::to<std::vector>(valid_prices);
	const double mean = stock_prices::average(valid_prices_as_vector);

	std::cout << "with average " << mean << "\n";

	double potential_profit = stock_prices::profit_on_first_uptick(valid_prices_as_vector);
	std::cout << "Potential profit " << potential_profit << "\n";

	const double required_profit = 1.75;

	bool possible = stock_prices::required_profit_possible(valid_prices_as_vector, required_profit);
	std::cout << "Required profit possible: " << possible << '\n';
}
