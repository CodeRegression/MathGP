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
		SingularNode(int id) : Node(id) 
		{
			_child = nullptr;
		}

		~SingularNode() { if (_child != nullptr) delete _child; }

		virtual int GetChildCount() { return 1; }

		virtual Node * GetChild(int index) 
		{
			if (index == 0) return _child;
			else throw runtime_error("Invalid child index");
		}

		virtual void SetChild(int index, Node * node) 
		{
			if (index == 0) { _child = UpdateChild(node, 0); }
			else throw runtime_error("Invalid child index");
		}

		inline Node * GetChild() { return _child; }
		inline void SetChild(Node * value) { _child = UpdateChild(value, 0); }
	};
}
