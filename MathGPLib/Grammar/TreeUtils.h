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
#include "BFTraversal.h"
#include "TreeFactory.h"
#include "TreeEncoder.h"

namespace NVL_AI
{
	class TreeUtils
	{
	public:
		static string GetCode(Node * tree);
		static double Evaluate(Node * tree, vector<double>& params);
		static void GetTreeEncoding(Node * tree, vector<double>& encoding);
		static NVL_AI::Node * BuildTreeFromEncoding(const vector<double>& encoding, int depthLimit, int inputCount, NVLib::Range<int>* constantRange);
		static void SavePopulation(ostream& writer, vector<Node *>& population);
		static void LoadPopulation(istream& reader, vector<Node *>& population);
	};
}