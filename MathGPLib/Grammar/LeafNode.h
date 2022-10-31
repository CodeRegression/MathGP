//--------------------------------------------------
// A description of the node
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
	class LeafNode : public Node
	{
	public:
		LeafNode(int id) : Node(id) {}
		
		virtual int GetChildCount() { return 0; }
		virtual Node * GetChild(int index) { throw runtime_error("Invalid child index"); }
		virtual void SetChild(int index, Node * node) { throw runtime_error("Cannot set a child on a leaf node"); }
	};
}