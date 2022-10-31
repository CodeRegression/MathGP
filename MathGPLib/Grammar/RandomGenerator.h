//--------------------------------------------------
// A random generator (that allows for random numbers to be swapped out during unit testing)
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/RandomUtils.h>

namespace NVL_AI
{
	class RandomGenerator
	{
	public:
		RandomGenerator();

		virtual void Initializer();
		virtual int Get(int min, int max);
	};
}
