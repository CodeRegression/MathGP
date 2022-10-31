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

		virtual string GetType() override;
		virtual string ToString() override;

		virtual double Evaluate(vector<double>& params) override;

		virtual Node * Clone(int id) override;

		virtual void UpdateCode(vector<double>& code) override;
	};
}