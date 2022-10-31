//--------------------------------------------------
// A node that returns a constant
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <NVLib/StringUtils.h>

#include "LeafNode.h"

namespace NVL_AI
{
	class ConstantNode : public LeafNode
	{
	private:
		double _value;
	public:
		ConstantNode(int id, double value);

		virtual string GetType();
		virtual string ToString();

		virtual double Evaluate(vector<double>& params);

		virtual Node * Clone(int id);

		inline double& GetValue() { return _value; }
	};
}
