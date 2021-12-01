/// @file CentralPolygonalNumbers.cpp
/// @brief Implementation file for CentralPolygonalNumbers class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <iostream>
#include <fstream>
#include <string>
#include "CentralPolygonalNumbers.h"

CentralPolygonalNumbers::CentralPolygonalNumbers()
{
	m_nMax = 0;
	mp_iNumbers = new int[m_nMax + 1];

	for (int n = 0; n <= m_nMax; n++)
	{
		mp_iNumbers[n] = (n * n + n + 2) / 2;
	}
}

CentralPolygonalNumbers::CentralPolygonalNumbers(int nMax)
{
	m_nMax = nMax;
	mp_iNumbers = new int[m_nMax + 1];

	for (int n = 0; n <= m_nMax; n++)
	{
		mp_iNumbers[n] = (n * n + n + 2) / 2;
	}
}

CentralPolygonalNumbers::~CentralPolygonalNumbers()
{
	delete[] mp_iNumbers;
	mp_iNumbers = nullptr;

	std::cout << "~CentralPolygonalNumbers() called" << std::endl;
}

void CentralPolygonalNumbers::display()
{
	for (int n = 0; n <= m_nMax; n++)
	{
		std::cout << "n: " << n << ", maximum number of pieces: " << mp_iNumbers[n] << std::endl;
	}
}

bool CentralPolygonalNumbers::save(std::string strFilename)
{
	std::ofstream ofsNumbers;
	ofsNumbers.open(strFilename + ".txt");

	for (int n = 0; n <= m_nMax; n++)
	{
		ofsNumbers << "n: " << n << ", maximum number of pieces: " << mp_iNumbers[n] << std::endl;
	}

	ofsNumbers.close();

	return true;
}