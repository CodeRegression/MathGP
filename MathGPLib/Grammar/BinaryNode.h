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
		BinaryNode(int id) : Node(id)
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

		virtual Node * GetChild(int index) 
		{
			if (index == 0) return _child1;
			else if (index == 1) return _child2;
			else throw runtime_error("Invalid child index");
		}

		virtual void SetChild(int index, Node * node) 
		{
			if (index == 0) { _child1 = UpdateChild(node, 0); }
			else if (index == 1) { _child2 = UpdateChild(node, 1); }
			else throw runtime_error("Invalid child index");	
		}

		inline Node * GetChild1() { return _child1; }
		inline Node * GetChild2() { return _child2; }

		inline void SetChild1(Node * value) { _child1 = UpdateChild(value, 0); }
		inline void SetChild2(Node * value) { _child2 = UpdateChild(value, 1); }
	};
}
