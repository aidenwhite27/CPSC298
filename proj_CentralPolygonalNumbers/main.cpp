/// @file main.cpp
/// @brief main function for file CentralPolygonalNumbers
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include "CentralPolygonalNumbers.h"

int main()
{
	CentralPolygonalNumbers cpn(10);
	cpn.display();
	cpn.save("CPN");

	return 0;
}