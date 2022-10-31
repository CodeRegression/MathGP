//--------------------------------------------------
// A node representing an inversion operation
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
	class InvertNode : public SingularNode
	{
	public:
		InvertNode(int id);

		virtual string GetType();
		virtual string ToString();

		virtual double Evaluate(vector<double>& params);

		virtual Node * Clone(int id);
	};
}
