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
		LeafNode(int id, int inputCount) : Node(id, inputCount) {}
		virtual int GetChildCount() { return 0; }
	};
}
