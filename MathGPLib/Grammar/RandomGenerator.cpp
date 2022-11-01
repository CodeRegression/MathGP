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
	return NVLib::RandomUtils::GetInteger(NVLib::Range<int>(min, max + 1));
}
