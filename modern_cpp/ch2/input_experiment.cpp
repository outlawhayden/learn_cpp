#include <iostream>
#include <limits>

int main()
{
	const double largest = std::numeric_limits<double>::max();
	std::cout << "Please enter a number up to " << largest << ".\n>";
	double number{};
	std::cin >> number;
	if (std::cin)
	{
		std::cout << number << '\n';
	}
	else
	{
		std::cout << "Something went wrong. \n";
	}
}

