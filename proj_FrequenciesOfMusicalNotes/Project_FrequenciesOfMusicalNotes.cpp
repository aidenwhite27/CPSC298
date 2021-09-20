// @file Programming Project: Musical Note Frequencies
// @brief A program that computes the frequency and wavelength of specific musical notes
// @author Aiden White aiwhite@chapman.edu

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	const double REFERENCE_FREQUENCY = 16.35; // The frequency of C in the zeroth octave
	const double D_TWELFTH_ROOT_OF_TWO = 1.059463094359;
	double computedFrequency = 0.0;
	int octaveNumber = 0;
	int semitoneNumber = 0; // Half-step value, within the octave (values range 0 to 11 inclusive)
	const double SPEED_OF_SOUND = 345;
	double wavelength = 0.0;
	string noteName = "";

	cout << "Reference Frequency: " << REFERENCE_FREQUENCY << " Hz" << endl;
	cout << "Speed of Sound: " << SPEED_OF_SOUND << " m/s" << endl;

	// C0
	noteName = "C0";
	octaveNumber = 0;
	semitoneNumber = 0;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << 
		"; frequency: " << computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	// C#0
	noteName = "C#0";
	octaveNumber = 0;
	semitoneNumber = 1;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << "; frequency: " <<
		computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	// D0
	noteName = "D0";
	octaveNumber = 0;
	semitoneNumber = 2;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << "; frequency: " <<
		computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	// C4
	noteName = "C4";
	octaveNumber = 4;
	semitoneNumber = 0;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << "; frequency: " <<
		computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	// D#7
	noteName = "D#7";
	octaveNumber = 7;
	semitoneNumber = 3;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << "; frequency: " <<
		computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	// C8
	noteName = "C8";
	octaveNumber = 8;
	semitoneNumber = 0;
	computedFrequency = REFERENCE_FREQUENCY * pow(2, octaveNumber) * pow(D_TWELFTH_ROOT_OF_TWO, semitoneNumber);
	wavelength = (SPEED_OF_SOUND * 100) / computedFrequency;
	cout << "Note: " << noteName << "; nu: " << octaveNumber << "; k: " << semitoneNumber << "; frequency: " <<
		computedFrequency << " Hz; wavelength: " << wavelength << " cm" << endl;

	return 0;
}