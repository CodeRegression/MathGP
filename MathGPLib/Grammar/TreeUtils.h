//--------------------------------------------------
// A set of utilities for processing a tree
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#pragma once

#include <sstream>
#include <iostream>
using namespace std;

#include "Node.h"

namespace NVL_AI
{
	class TreeUtils
	{
	public:
		static string GetCode(Node * tree);
		static double Evaluate(Node * tree, vector<double>& params);
	};
}