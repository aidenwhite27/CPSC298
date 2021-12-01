#if !defined(CentralPolygonalNumbers_H)
#define CentralPolygonalNumbers_H
/// @file CentralPolygonalNumbers.h
/// @brief Header file for CentralPolygonalNumbers class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <string>

class CentralPolygonalNumbers 
{
public:
	CentralPolygonalNumbers();
	CentralPolygonalNumbers(int nMax);
	~CentralPolygonalNumbers();
	void display();
	bool save(std::string strFilename);

private:
	int m_nMax;
	int* mp_iNumbers;
};
#endif
