#include <expected>
#include <iostream>
#include <string>

std::expected<double, std::string> get_number(std::istream & input_stream){
	double number{};
	input_stream >> number ;
	if(input_stream)
	{
		return number;
	}
	return std::unexpected{"That's not a number!"};
}

int main()
{
	std::cout << "Please enter a number.\n";
	while(true){
		auto number = get_number(std::cin);
		if(number.has_value())
		{
			std::cout << "Got " << number.value() << " thanks!\n";
		}
		else
		{
			std::cout << number.error() << "\n";
		break;
		}	
	}

}

