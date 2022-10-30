//--------------------------------------------------
// A node that only has one child
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "Node.h"

namespace NVL_AI
{
	class SingularNode : public Node
	{
	private:
		Node * _child;

	public:
		SingularNode(int id, int inputCount) : Node(id, inputCount) 
		{
			_child = nullptr;
		}

		virtual int GetChildCount() { return 1; }

		inline Node * GetChild() { return _child; }
		inline void SetChild(Node * value) { _child = value; }
	};
}
