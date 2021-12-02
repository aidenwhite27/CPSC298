/// @file ElectronicControlUnit.cpp
/// @brief Implementation file for ElectronicControlUnit class
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>
#include "ElectronicControlUnit.h"

ElectronicControlUnit::ElectronicControlUnit()
{
	m_bActivatedHydraulicJacks = false;
	m_bActivatedBeltTires = false;
	m_bActivatedIRIllumination = false;
}

ElectronicControlUnit::~ElectronicControlUnit()
{

}

void ElectronicControlUnit::handleCommand(char cCommand)
{
	switch(cCommand)
	{
		case 'A':
		case 'a':
			actuateHydraulicJacks();
			break;
		case 'B':
		case 'b':
			actuateBeltTires();
			break;
		case 'E':
		case 'e':
			actuateIRIllumination();
			break;
		case 'X':
		case 'x':
			exit(0);
			break;
	}
}

void ElectronicControlUnit::displayWheel()
{
	std::cout << "       (A)" << std::endl;
	std::cout << "   (F) (G) (B)" << std::endl;
	std::cout << "   (E)     (C)" << std::endl;
	std::cout << "       (D)" << std::endl;
}

void ElectronicControlUnit::actuateHydraulicJacks()
{
	if (!m_bActivatedHydraulicJacks)
	{
		if (m_bActivatedBeltTires)
		{
			m_bActivatedBeltTires = false;
			std::cout << "Belt Tires deactivated" << std::endl;
		}

		m_bActivatedHydraulicJacks = true;
		std::cout << "Hydraulic Jacks activated" << std::endl;
	}
	else
	{
		m_bActivatedHydraulicJacks = false;
		std::cout << "Hydraulic Jacks deactivated" << std::endl;
	}
}

void ElectronicControlUnit::actuateBeltTires()
{
	if (!m_bActivatedBeltTires)
	{
		m_bActivatedBeltTires = true;
		std::cout << "Belt Tires activated" << std::endl;
	}
	else
	{
		m_bActivatedBeltTires = false;
		std::cout << "Belt Tires deactivated" << std::endl;
	}
}

void ElectronicControlUnit::actuateIRIllumination()
{
	if (!m_bActivatedIRIllumination)
	{
		m_bActivatedIRIllumination = true;
		std::cout << "Infrared Illumination activated" << std::endl;
	}
	else
	{
		m_bActivatedIRIllumination = false;
		std::cout << "Infrared Illumination deactivated" << std::endl;
	}
}
