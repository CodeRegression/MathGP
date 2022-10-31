//--------------------------------------------------
// A node that returns a literal
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

#include "LeafNode.h"

namespace NVL_AI
{
	class LiteralNode : public LeafNode
	{
	private:
		int _index;

	public:
		LiteralNode(int id, int index);

		virtual string GetType() override;
		virtual string ToString() override;

		virtual double Evaluate(vector<double>& params) override;

		virtual Node * Clone(int id) override;

		virtual void UpdateCode(vector<double>& code) override;

		inline int& GetIndex() { return _index; }
	};
}