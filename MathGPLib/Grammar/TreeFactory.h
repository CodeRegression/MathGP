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

	public:
		TreeFactory(RandomGenerator * generator);
		~TreeFactory();

		NVL_AI::Node * GetRandomTree(int depthLimit);
		NVL_AI::Node* Breed(NVL_AI::Node * mother, NVL_AI::Node * father);
	private:
		NVL_AI::Node* GetRandomLeafNode();
		NVL_AI::Node * GetRandomBinaryNode();
		NVL_AI::Node * GetRandomSingularNode();
		NVL_AI::Node * GetRandomNode(int index);
		int GetNodeType(const vector<Vec2i>& weights);
	};
}