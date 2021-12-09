/// @file main.cpp
/// @brief class definition for sigma and main function for file Exceptions
/// @author aiwhite@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++
#include <iostream>
#include <stdexcept>
#include <string>

// Sum the integers from 1 to n. For example, if n is 5, then
// sigma returns the sum 1 + 2 + 3 + 4 + 5 == 15.
// @param n unsigned integer upper bound of summation
// @pre n >= 1
// @post return value is the sum of the integers from 1 to n.
// @return sum of the integers from 1 to n, where n is
//		   specified as an argument or 0 if an error occurred.
unsigned long sigma(unsigned long n)
{
	unsigned long sum = 0;
	unsigned long expectedSum = 0;
	std::string preViolation = "Precondition n>=1 violated, invalid value for argument n: " + std::to_string(n) +
		" (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";
	
	try
	{
		// Check preconditions
		if (!(n >= 1)) 
		{
			throw std::runtime_error(preViolation);
		}

		// Function body
		for (int i = 0; i <= n; i++)
		{
			sum += i;
		}

		//Check postconditions
		expectedSum = (n * (n + 1)) / 2;

		std::string postViolation = "Postcondition sum == (n(n+1))/2 violated: sum: " + std::to_string(sum) +
			"; n(n+1)/2: " + std::to_string(expectedSum) + " (Loc: " + __FILE__ + ", " + std::to_string(__LINE__) + ")";


		if (sum != expectedSum)
		{
			throw std::runtime_error(postViolation);
		}
	}
	catch(std::runtime_error & ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
		std::cout << "Cannot compute sum, returning 0" << std::endl;
		sum = 0; // 0 is returned to indicate an error occurred.
	}

	return sum;
}

int main()
{
	int sum = sigma(5);
	std::cout << "sigma(5) = " << sum << std::endl;
	sum = sigma(0);
	std::cout << "sigma(0) = " << sum << std::endl;

	return 0;
}