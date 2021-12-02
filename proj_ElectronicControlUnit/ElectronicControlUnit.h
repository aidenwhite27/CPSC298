#if !defined(ElectronicControlUnit_H)
#define ElectronicControlUnit_H
/// @file ElectronicControlUnit.h
/// @brief Header file for ElectronicControlUnit class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

class ElectronicControlUnit
{
private:
	bool m_bActivatedHydraulicJacks; // Button A
	bool m_bActivatedBeltTires;      // Button B
	bool m_bActivatedIRIllumination; // Button E
public:
	ElectronicControlUnit();
	~ElectronicControlUnit();
	void handleCommand(char cCommand);
	void displayWheel();
	void actuateHydraulicJacks();
	void actuateBeltTires();
	void actuateIRIllumination();
};
#endif
