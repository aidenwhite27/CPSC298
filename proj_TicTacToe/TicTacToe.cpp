/// @file TicTacToe.cpp
/// @brief Implementation file for TicTacToe class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>
#include <tuple>

#include "TicTacToe.h"

TicTacToeGame::TicTacToeGame()
{
	srand(5000); // Setting seed for random number generation

	// Allocating memory for grid
	this->pp_cGrid = new char* [3];
	for (int iRow = 0; iRow < 3; iRow++) {
		this->pp_cGrid[iRow] = new char[3];
	}

	initializeGrid();
}

TicTacToeGame::~TicTacToeGame()
{
	for (int iRow = 0; iRow < 3; iRow++) 
	{
		delete[] this->pp_cGrid[iRow];
	}

	delete[] pp_cGrid;
	pp_cGrid = nullptr;
}

void TicTacToeGame::initializeGrid()
{
	// Assigning '~' to all grid spaces
	for (int iRow = 0; iRow < 3; iRow++) {
		for (int iCol = 0; iCol < 3; iCol++) {
			this->pp_cGrid[iRow][iCol] = '~';
		}
	}
	return;
}

void TicTacToeGame::displayGrid() 
{
	std::cout << std::endl;

	// Loop through grid, printing out char at each location
	for(int iRow = 0; iRow < 3; iRow++)
	{
		std::cout << " ";
		
		for(int iCol = 0; iCol < 3; iCol++)
		{
			std::cout << this->pp_cGrid[iRow][iCol] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

std::tuple<int, int> TicTacToeGame::promptForGridCoord()
{
	int iRow = 0;
	int iCol = 0;
	bool rowValid = false;
	bool colValid = false;
	bool spaceEmpty = false;

	do { // Outer loop first prompts the user to make a move, but repeats if that space is already taken
		do { // Checks for valid row number, if not then it repeats
			std::cout << "Please enter grid row number: " << std::endl;
			std::cin >> iRow;
			if (iRow == 0 || iRow == 1 || iRow == 2) {
				rowValid = true;
			}
			else {
				std::cout << "The grid row number should be 0, 1, or 2." << std::endl;
			}
		} while (!rowValid);

		do { // Checks for valid column number, if not then it repeats
			std::cout << "Please enter grid column number: " << std::endl;
			std::cin >> iCol;
			if (iCol == 0 || iCol == 1 || iCol == 2) {
				colValid = true;
			}
			else {
				std::cout << "The grid row number should be 0, 1, or 2." << std::endl;
			}
		} while (!colValid);

		// Checks if the space is empty so that the outer loop can break
		if(this->pp_cGrid[iRow][iCol] == '~')
		{
			spaceEmpty = true;
		}
		else
		{
			std::cout << "That space is already taken, please enter a different one:" << std::endl;
		}

	} while (!spaceEmpty);

	std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iCol);

	return tupleCoord;
}

void TicTacToeGame::playerMove() 
{
	int iRow = 0;
	int iCol = 0;

	std::tie(iRow, iCol) = promptForGridCoord();

	this->pp_cGrid[iRow][iCol] = 'X';

	return;
}

// This function generates a pseudo-random move by the computer. Since the rand() function always generates
// the same sequence given a specific seed, the computer will play the same moves each game unless a space is occupied.
// If a space is occupied, then the computer will select the next randoms in the sequence, so this can lead to different
// game variations based on how the user plays. This gives the appearance that the computer makes some random choices,
// although they are actually the same unless the seed is reset each game. Currently, the seed is hardcoded in the
// TicTacToeGame constructor.
void TicTacToeGame::computerMove()
{
	bool spaceEmpty = false;
	int iRow = 0;
	int iCol = 0;

	do {
		int iRowRandom = rand() % 3; //Generates random number from 0-2
		int iColRandom = rand() % 3; //Generates random number from 0-2

		if (this->pp_cGrid[iRowRandom][iColRandom] == '~')
		{
			spaceEmpty = true;
			iRow = iRowRandom;
			iCol = iColRandom;
		}
	} while (!spaceEmpty);

	this->pp_cGrid[iRow][iCol] = 'O';

	return;
}

// This is a very inefficient solution for checking if the game is won. I am using it here because I could not think
// of a more elegant solution and I'm limited by time. It is manageable for a small 3x3 grid, but would not scale
// well to larger situations. It works by checking if any three spaces that form a line are occupied by the same character,
// and that character does not represent a blank space. If so, the game is won.
bool TicTacToeGame::isWon()
{
	if ((this->pp_cGrid[0][0] == this->pp_cGrid[0][1]) && (this->pp_cGrid[0][1] == this->pp_cGrid[0][2]) &&
		(this->pp_cGrid[0][0] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[1][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[1][1] == this->pp_cGrid[1][2]) &&
		(this->pp_cGrid[1][0] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[2][0] == this->pp_cGrid[2][1]) && (this->pp_cGrid[2][1] == this->pp_cGrid[2][2]) &&
		(this->pp_cGrid[2][0] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][0]) && (this->pp_cGrid[1][0] == this->pp_cGrid[2][0]) &&
		(this->pp_cGrid[0][0] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[0][1] == this->pp_cGrid[1][1]) && (this->pp_cGrid[1][1] == this->pp_cGrid[2][1]) &&
		(this->pp_cGrid[0][1] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][2]) && (this->pp_cGrid[1][2] == this->pp_cGrid[2][2]) &&
		(this->pp_cGrid[0][2] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[1][1] == this->pp_cGrid[2][2]) &&
		(this->pp_cGrid[0][0] != '~'))
	{
		return true;
	}
	else if ((this->pp_cGrid[2][0] == this->pp_cGrid[1][1]) && (this->pp_cGrid[1][1] == this->pp_cGrid[0][2]) &&
		(this->pp_cGrid[2][0] != '~'))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TicTacToeGame::isDraw()
{
	// Loop through the entire grid, if there are any blank spaces, then it is not a draw. If the entire grid
	// does not contain any blank spaces, then it is a draw.
	for (int iRow = 0; iRow < 3; iRow++)
	{
		for (int iCol = 0; iCol < 3; iCol++)
		{
			if (this->pp_cGrid[iRow][iCol] == '~')
			{
				return false;
			}
		}
	}
	return true;
}

void TicTacToeGame::play()
{
	int iRow = 0;
	int iCol = 0;

	this->displayGrid();

	this->playerMove();

	this->displayGrid();

	// If the game is not won or drawn after the player's move, then the computer will move
	if (!this->isWon() && !this->isDraw()) 
	{
		this->computerMove();

		// Checks if the game is won by the computer's move
		// Note: The game will never be drawn by the computer's move if the player moves first, so we do not
		// need to check for it here.
		if(this->isWon())
		{
			this->displayGrid();
			std::cout << "Game Over: O wins!" << std::endl;
		}
	}
	else if (this->isDraw()) 
	{
		std::cout << "Game Over: Draw!" << std::endl;
	}
	else
	{
		std::cout << "Game Over: X wins!" << std::endl;
	}
}