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

#include <MathGPLib/Grammar/RandomGenerator.h>

namespace NVL_Test
{
	class TestGenerator : public RandomGenerator
	{
	private:
		vector<double> _values;
		int _position;
	public:
		TestGenerator(const vector<double>& values) : _values(values), _position(0) {} 

		virtual void Initializer() override {}
		
		virtual int Get(int min, int max) override 
		{ 
			auto result = _values[_position++];
			if (result < min || result > max) throw runtime_error("Value is out of range");
			return result; 
		}
	};
}