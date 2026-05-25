#include <exception>
#include <iostream>


double get_number(std::istream & input_stream){
	double number{};
	input_stream >> number;
	if (input_stream)
	{
		return number;
	}
	throw std::exception{};
}

int main() {
	try{
		std::cout << "Please enter a number:\n";
		double number = get_number(std::cin);
		std::cout << "Got " << number << ", thanks!\n";
	}
	catch(const std:: exception & ex){
		std::cout << "Something went wrong!\n";
	}
}
