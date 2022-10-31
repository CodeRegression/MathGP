//--------------------------------------------------
// A base class for the node entity
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace NVL_AI
{
	class Node
	{
	private:
		int _id;
	public:
		Node(int id) : _id(id) {}

		virtual string GetType() = 0;
		virtual int GetChildCount() = 0;
		virtual string ToString() = 0;

		virtual double Evaluate(vector<double>& params) = 0;
		virtual Node * Clone(int id) = 0;
		virtual Node * GetChild(int index) = 0;
		virtual void SetChild(int index, Node * node) = 0;

		inline int& GetId() { return _id; }
	};
}
