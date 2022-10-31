//--------------------------------------------------
// A node representing an addition operation
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
	class AddNode : public BinaryNode
	{
	public:
		AddNode(int id);

		virtual string GetType();
		virtual string ToString();

		virtual double Evaluate(vector<double>& params);

		virtual Node * Clone(int id);
	};
}
