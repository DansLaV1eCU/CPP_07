#include <iostream>
#include <string>

#include "Array.hpp"

static void printTitle( const std::string& title )
{
	std::cout << "\n== " << title << " ==\n";
}

int main( void )
{
	printTitle("empty array");
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;

	printTitle("basic values");
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
	{
		numbers[i] = static_cast<int>(i * 10);
		std::cout << numbers[i] << (i + 1 == numbers.size() ? '\n' : ' ');
	}

	printTitle("copy semantics");
	Array<int> copied(numbers);
	copied[0] = 999;
	std::cout << "original[0]: " << numbers[0] << std::endl;
	std::cout << "copy[0]: " << copied[0] << std::endl;

	printTitle("assignment semantics");
	Array<std::string> words(3);
	words[0] = "alpha";
	words[1] = "beta";
	words[2] = "gamma";

	Array<std::string> assigned;
	assigned = words;
	assigned[1] = "changed";
	std::cout << "original[1]: " << words[1] << std::endl;
	std::cout << "assigned[1]: " << assigned[1] << std::endl;

	printTitle("bounds checking");
	try
	{
		std::cout << assigned[3] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}