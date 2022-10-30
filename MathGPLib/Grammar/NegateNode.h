//--------------------------------------------------
// A node representing a division operation
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

#include "SingularNode.h"

namespace NVL_AI
{
	class NegateNode : public SingularNode
	{
	public:
		NegateNode(int id, int inputCount);

		virtual string GetType();
		virtual string ToString();

		virtual double Evaluate(vector<double>& params);

		virtual Node * Clone(int id);
	};
}