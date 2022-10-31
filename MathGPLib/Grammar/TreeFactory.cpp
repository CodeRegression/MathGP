//--------------------------------------------------
// Implementation of class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include "TreeFactory.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param generator A random generator for resolving trees
 */
TreeFactory::TreeFactory(RandomGenerator * generator, int depthLimit, int inputCount, NVLib::Range<int>* constantRange) 
	: _generator(generator), _depthLimit(depthLimit), _inputCount(inputCount), _constantRange(constantRange)
{
	// Extra initialization can go here
}

/**
 * @brief Main Terminator
 */
TreeFactory::~TreeFactory()
{
	delete _generator; delete _constantRange;
}

//--------------------------------------------------
// Create
//--------------------------------------------------

/**
 * @brief Retrieve a randomly generated tree
 * @param depthLimit The depth limit of the associated tree
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomTree(int depthLimit)
{
	// Create working variables
	auto current = vector<Node *>(); auto next = vector<Node *>(); int level = 0;

	// Build the root tree
	auto firstNodeType = GetNodeType(vector<Vec2i> { Vec2i(2, 1), Vec2i(3, 8)} );
	auto root = firstNodeType == 1 ? GetRandomSingularNode() : GetRandomBinaryNode();
	current.push_back(root);

	// Add random children
	while (current.size() > 0) 
	{
		for (auto i = 0; i < current.size(); i++) 
		{
			auto node = current[i];

			for (auto childId = 0; childId < node->GetChildCount(); i++) 
			{
				auto weights = (depthLimit < level++) ? vector<Vec2i> { Vec2i(1, 1), Vec2i(2,2), Vec2i(3, 7)} : vector<Vec2i> { Vec2i(1,1)};
				auto nodeTypeId = GetNodeType(weights);
				auto child = GetRandomNode(nodeTypeId);
				node->SetChild(childId, child); next.push_back(child);
			}
		}

		current.clear(); 
		for (auto i = 0; i < next.size(); i++) current[i] = next[i]; 
		next.clear();
	}
	
	// Return the result	
	return root;
}

//--------------------------------------------------
// Breed
//--------------------------------------------------

/**
 * @brief Performs the breeding operation
 * @param mother The given mother node
 * @param father The given father node
 * @return Node* Returns a Node*
 */
NVL_AI::Node* TreeFactory::Breed(Node * mother, Node * father)
{
	throw runtime_error("Not implemented");
}

//--------------------------------------------------
// Helpers
//--------------------------------------------------

/**
 * @brief Retrieve a random generated node
 * @param index The index of the node that we are getting
 * @return NVL_AI::Node The node that we have randomly generated
 */
NVL_AI::Node * GetRandomNode(int index) 
{
	throw runtime_error("Not Implemented");
}

/**
 * @brief Retrieve a random leaf node
 * @return Node* Returns a Node*
 */
NVL_AI::Node* TreeFactory::GetRandomLeafNode()
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Retrieve a random binary node
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomBinaryNode()
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Retrieve a random singular node
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomSingularNode()
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Retrieve the node type
 * @param weights A set of node types and the weight of that node type
 * @return int Returns a int
 */
int TreeFactory::GetNodeType(const vector<Vec2i>& weights)
{
	throw runtime_error("Not implemented");
}