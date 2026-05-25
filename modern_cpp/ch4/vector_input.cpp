#include<vector>
#include<iostream>
#include<expected>
#include<limits>

std::expected<double, std::string> get_number(std::istream & input_stream)
{
	double number{};
	input_stream >> number;
	if(input_stream)
	{
		return number;
	}
	input_stream.clear();
	input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return std::unexpected{"That's not a number..."};
}

void remove_from_vector()
{
	std::vector numbers{1,3,7,9,0};
	numbers.erase(numbers.begin());
	numbers.erase(numbers.begin() + 1, numbers.begin() + 2);
	for(const auto number: numbers)
	{
		std::cout << number << '\n';
	}
}

void vector_insert()
{
	std::vector<int> numbers{0,1};
	auto iterator = numbers.begin();
	numbers.insert(++iterator, -123);
	for(const auto number : numbers)
	{
		std::cout << number << '\n';
	}
}

void vector_experiment()
{
	std::vector numbers{0,1};
	numbers.push_back(-123);
	for(const auto number: numbers)
	{
		std::cout << number << '\n';
	}
}

int main()
{
	//vector_experiment();
	//vector_insert();
	std::cout << "Please enter some numbers.\n>";
	std::vector<double> numbers{};
	auto number = get_number(std::cin);
	while(number.has_value())
	{
		numbers.push_back(number.value());
		std::cout << "Got " << number.value() << " thanks!\n>";
		number = get_number(std::cin);
	}
	std::cout << number.error() << '\n';

	std::cout << "You entered\n";
	for(const auto & number : numbers)
	{
		std::cout << number << '\n';
	}
}
