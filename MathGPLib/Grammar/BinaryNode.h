//--------------------------------------------------
// A node that is a binary node
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
	class BinaryNode : public Node
	{
	private:
		Node * _child1;
		Node * _child2;
	public:
		BinaryNode(int id, int inputCount) : Node(id, inputCount)
		{
			_child1 = nullptr;
			_child2 = nullptr;
		}

		~BinaryNode() 
		{
			if (_child1 != nullptr) delete _child1;
			if (_child2 != nullptr) delete _child2;
		}

		virtual int GetChildCount() { return 2; }

		inline Node *& GetChild1() { return _child1; }
		inline Node *& GetChild2() { return _child2; }

		inline void SetChild1(Node * value) { _child1 = value; }
		inline void SetChild2(Node * value) { _child2 = value; }
	};
}
