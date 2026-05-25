#include<algorithm>
#include<iostream>
#include<vector>

#include "input.h"

int main()
{
	stock_prices::test_input();

	std::cout << "Please enter some numbers.\n";
	auto prompt = [] () {std::cout << '>';};
	auto prices = stock_prices::get_prices(std::cin, prompt);
	std::cout << "Got " << prices.size() << " price(s) \n";
}
