#include <exception>
#include <iostream>
#include <stdexcept>

double get_number(std::istream & input_stream)
{
	double number{};
	input_stream >> number;
	if(input_stream)
	{
		if(number >= 0.0)
		{
			return number;
		}
		throw std::invalid_argument("Please provide a nonnegative number.");
	}
	throw std::exception{};
}

int main()
{
	try
	{
		std::cout << "Please enter a number:\n";
		double number = get_number(std::cin);
		std::cout << "Got " << number << ", thanks!\n";
	}
	catch(const std::invalid_argument & ex)
	{
		std::cout << ex.what() << '\n';
	}
	catch(const std::exception & ex)
	{
		std::cout << "Something went wrong\n";
	}
}
