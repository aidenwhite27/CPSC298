/// @file main.cpp
/// @brief main function for file ElectronicControlUnit
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <iostream>
#include "ElectronicControlUnit.h"

int main() 
{
	ElectronicControlUnit ecu;

	std::cout << "Press X to turn off ignition or enter a steering wheel button (A, B, or E)" << std::endl;
	ecu.displayWheel();

	char cCommand;

	while (!std::cin.eof())
	{
		std::cin >> cCommand;

		ecu.handleCommand(cCommand);

		ecu.displayWheel();
	}

	return 0;
}