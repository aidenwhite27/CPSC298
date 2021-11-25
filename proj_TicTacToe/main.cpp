/// @file main.cpp
/// @brief main function for file TicTacToe
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>

#include "TicTacToe.h"

int main() 
{
	TicTacToeGame *game = new TicTacToeGame();
	
	std::cout << "Tic Tac Toe" << std::endl;
	std::cout << "The top row is number 0, the middle row number 1, and the bottom row is number 2." << std::endl;
	std::cout << "The left column is number 0, the middle column number 1, and the bottom column is number 2." << std::endl;

	do {
		game->play();
	} while (!game->isWon() && !game->isDraw());
	
	delete game;
	
	return 0;
}