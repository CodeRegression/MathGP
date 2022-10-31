//--------------------------------------------------
// A node representing a multiplication operation
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#include "BinaryNode.h"

namespace NVL_AI
{
	class MultiplyNode : public BinaryNode
	{
	public:
		MultiplyNode(int id);

		virtual string GetType();
		virtual string ToString();

		virtual double Evaluate(vector<double>& params);

		virtual Node * Clone(int id);
	};
}