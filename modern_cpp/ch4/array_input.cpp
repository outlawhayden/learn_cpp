#include <array>
#include <iostream>
#include <expected>
#include <limits>

void show_numbers(const std::array<double, 5u> & numbers)
{
	for(const auto number: numbers)
	{
		std::cout << number << '\n';
	}
}

void max_number(std::array<double, 5u> & numbers)
{
	double biggest = numbers[0];
	for(const auto number: numbers)
	{
		if(number > biggest)
		{
			biggest = number;
		}
	}
	std::cout << "The biggest number is " << biggest << '\n';
}

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
	return std::unexpected("That's not a number!");
}

void array_experiment()
{
	std::array<double, 5> numbers{};
	std::cout << numbers[0] << "\n";
	numbers[0] = 2.5;
	std::cout << numbers[0] << "\n";	
}

int main()
{
	std::cout << "Please enter some numbers:\n";
	std::array<double, 5u> numbers{};
	size_t count{0u};
	while(count < numbers.size())
	{
		std::cout << '>';
		auto number = get_number(std::cin);
		if(number.has_value())
		{
			numbers[count] = number.value();
			std::cout << "Got " << number.value() << ", thanks!\n";
		}
		else
		{
			std::cout << number.error() << "\n";
		}
		++count;
	}

	show_numbers(numbers);
	max_number(numbers);
}

