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

#include "RandomGenerator.h"

namespace NVL_AI
{
	class TreeEncoder : public RandomGenerator
	{
	private:
		vector<double> _values;
		int _position;
	public:
		TreeEncoder(const vector<double>& values) : _values(values), _position(0) {} 

		virtual void Initialize() override {}
		
		virtual int Get(int min, int max) override 
		{  
			if (_position > _values.size()) throw runtime_error("Encoding does not define a complete tree");
			return _values[_position++]; 
		}
	};
}