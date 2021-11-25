#if !defined(TicTacToe_H)
#define TicTacToe_H
/// @file TicTacToe.h
/// @brief Header file for TicTacToe class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <tuple>

class TicTacToeGame {
private:
	char** pp_cGrid;
private:
	void initializeGrid();
	void displayGrid();
	std::tuple<int, int> promptForGridCoord();
	void playerMove();
	void computerMove();
public:
	TicTacToeGame();
	~TicTacToeGame();
	bool isWon();
	bool isDraw();
	void play();
};
#endif
