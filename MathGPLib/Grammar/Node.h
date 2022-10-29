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
			int _inputCount;
		public:
			Node(int id, int inputCount) :
				_id(id), _inputCount(inputCount) {}

			virtual string GetType() = 0;
			virtual int GetChildCount() = 0;
			virtual string ToString() = 0;

			virtual double Evaluate(vector<double>& params) = 0;
			virtual Node * Clone() = 0;

			inline int& GetId() { return _id; }
			inline int& GetInputCount() { return _inputCount; }
	};
}
