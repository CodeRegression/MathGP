//--------------------------------------------------
// A factory for the generation of trees
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>

#include <NVLib/Model/Range.h>

#include "RandomGenerator.h"
#include "AddNode.h"
#include "ConstantNode.h"
#include "DivideNode.h"
#include "InvertNode.h"
#include "LiteralNode.h"
#include "MultiplyNode.h"
#include "NegateNode.h"
#include "SubtractNode.h"

namespace NVL_AI
{
	class TreeFactory
	{
	private:
		RandomGenerator * _generator;
		int _depthLimit;
		int _inputCount;
		NVLib::Range<int> * _constantRange;
	public:
		TreeFactory(RandomGenerator * generator, int depthLimit, int inputCount, NVLib::Range<int>* constantRange);
		~TreeFactory();

		NVL_AI::Node * GetRandomTree();
		NVL_AI::Node* Breed(NVL_AI::Node * mother, NVL_AI::Node * father);
	private:
		NVL_AI::Node * GetRandomNode(int typeIndex, int id);
		NVL_AI::Node * GetRandomLeafNode(int id);
		NVL_AI::Node * GetRandomBinaryNode(int id);
		NVL_AI::Node * GetRandomSingularNode(int id);
		int GetNodeType(const vector<Vec2i>& weights);
	};
}