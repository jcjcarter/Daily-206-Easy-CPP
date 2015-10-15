// Daily 206 Easy CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <functional>

int printRecursive(int step, int start, std::function<int(int)> &operation) {

	int value;
	if (step == 0)
	{
		value = start;
	}
	else {
		value = operation(printRecursive(step - 1, start, operation));
	}
	std::cout << "Term " << step << ": " << value << std::endl;
	return value;
}

int main()
{
	std::function<int(int)> operation = std
		::bind(std::plus<int>(), std::placeholders::_1, 0);

	std::string input, parsed;
	std::getline(std::cin, input);

	std::stringstream input_stringstream(input);

	while (getline(input_stringstream, parsed, ' '))
	{
		switch (parsed.at(0))
		{
		case '+':
			operation = std::bind(std::plus<int>(), std::bind(operation, std::placeholders::_1), std::stoi(parsed.substr(1)));
			break;
		case '-':
			operation = std::bind(std::minus<int>(), std::bind(operation, std::placeholders::_1), std::stoi(parsed.substr(1)));
			break;
		case '*':
			operation = std::bind(std::multiplies<int>(), std::bind(operation, std::placeholders::_1), std::stoi(parsed.substr(1)));
			break;
		case '/':
			operation = std::bind(std::divides<int>(), std::bind(operation, std::placeholders::_1), std::stoi(parsed.substr(1)));
			break;
		}
	}

	int start, repeats;

	std::cin >> start;
	std::cin >> repeats;

	printRecursive(repeats, start, operation);
    return 0;
}

