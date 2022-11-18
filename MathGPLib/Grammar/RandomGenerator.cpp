//--------------------------------------------------
// Implementation of class RandomGenerator
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include "RandomGenerator.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
RandomGenerator::RandomGenerator()
{
	// Base implementation stuff can ge added here
}

//--------------------------------------------------
// Initialize
//--------------------------------------------------

/**
 * @brief An initializer for setting up the random generator
 */
void RandomGenerator::Initialize()
{
	NVLib::RandomUtils::TimeSeedRandomNumbers();
}

//--------------------------------------------------
// Generate
//--------------------------------------------------

/**
 * @brief Retrieve the next random number
 * @param min The minimum value inclusive
 * @param max The maximum value inclusive
 * @return int Returns a int
 */
int RandomGenerator::Get(int min, int max)
{
	if (min > max) throw runtime_error("Parameters are in the wrong order!");
	auto range = (max - min) + 1;
	auto number = rand() % range;
	auto result = number + min;
	if (result < min || result > max) 
	{
		throw runtime_error("Something broke!");
	}
	return result;
}
