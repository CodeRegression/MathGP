//--------------------------------------------------
// A tool that allows for a breadthfirst traversal of a tree
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "Node.h"

namespace NVL_AI
{
	class BFTraversal
	{
		private:
			Node * _tree;
			int _position;
			vector<Node *> _layer;
		public:
			BFTraversal(Node * tree);

			Node * Next();

			inline int& GetPosition() { return _position; }

		private:
			void UpdateLayer();
	};
}
