#include <cassert>
#include <limits>
#include <sstream>

#include "input.h"

namespace stock_prices
{
	std::expected<double, std::string> get_number(std::istream & input_stream)
	{
		double number{};
		input_stream >> number;
		if(input_stream)
		{
			return number;
		}
		input_stream.clear();
		input_stream.ignore(
				std::numeric_limits<std::streamsize>::max(), '\n'
				);
		return std::unexpected{"That's not a number"};
	}
	std::vector<double> get_prices(std::istream & input_stream,
			std::function<void ()> prompt)
	{
		prompt();
		std::vector<double> numbers{};
		auto number = stock_prices::get_number(input_stream);
		while(number.has_value())
		{
			numbers.push_back(number.value());
			prompt();
			number = stock_prices::get_number(input_stream);
		}
		return numbers;
	}
	void test_input()
	{
		std::stringstream no_input{""};
		auto no_op = [] () {};
		assert(get_prices(no_input, no_op).empty());

		std::stringstream some_input{"1"};
		assert(get_prices(some_input, no_op).size() == 1);
	}
}
