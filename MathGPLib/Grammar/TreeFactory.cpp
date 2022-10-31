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
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomTree()
{
	// Create working variables
	auto current = vector<Node *>(); auto next = vector<Node *>(); int level = 0; int id = 1;

	// Build the root tree
	auto firstNodeType = GetNodeType(vector<Vec2i> { Vec2i(2, 1), Vec2i(3, 8)} );
	auto root = firstNodeType == 1 ? GetRandomSingularNode(id++) : GetRandomBinaryNode(id++);
	current.push_back(root);

	// Add random children
	while (current.size() > 0) 
	{
		for (auto i = 0; i < current.size(); i++) 
		{
			auto node = current[i];

			for (auto childId = 0; childId < node->GetChildCount(); i++) 
			{
				auto weights = (_depthLimit < level++) ? vector<Vec2i> { Vec2i(1, 1), Vec2i(2,2), Vec2i(3, 7)} : vector<Vec2i> { Vec2i(1,1)};
				auto nodeTypeId = GetNodeType(weights);
				auto child = GetRandomNode(nodeTypeId, id++);
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
 * @param typeIndex The index of the type of node that we are getting
 * @param id The identifier to assign to nodes
 * @return NVL_AI::Node The node that we have randomly generated
 */
NVL_AI::Node * TreeFactory::GetRandomNode(int typeIndex, int id) 
{
	if (typeIndex == 1) return GetRandomLeafNode(id);
	else if (typeIndex == 2) return GetRandomSingularNode(id);
	else if (typeIndex == 3) return GetRandomBinaryNode(id);
	else throw runtime_error("Unknown type index");
}

/**
 * @brief Retrieve a random leaf node
 * @param id The node identifier
 * @return Node* Returns a Node*
 */
NVL_AI::Node * TreeFactory::GetRandomLeafNode(int id)
{
	auto nodeId = _generator->Get(0, 1);

	if (nodeId == 0) 
	{
		auto value = _generator->Get(_constantRange->GetMin(), _constantRange->GetMax());
		return new ConstantNode(id, value);
	}
	else 
	{
		auto index = _generator->Get(0, _inputCount);
		return new LiteralNode(id, index);
	}
}

/**
 * @brief Retrieve a random binary node
 * @param id The node identifier
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomBinaryNode(int id)
{
	auto nodeId = _generator->Get(0, 3);
	if (nodeId == 0) return new AddNode(id);
	else if (nodeId == 1) return new SubtractNode(id);
	else if (nodeId == 2) return new MultiplyNode(id);
	else return new DivideNode(id);
}

/**
 * @brief Retrieve a random singular node
 * @param id The node identifier
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomSingularNode(int id)
{
	auto nodeId = _generator->Get(0, 3);
	if (nodeId == 0) return new NegateNode(id);
	else return new InvertNode(id);
}

/**
 * @brief Retrieve the node type
 * @param weights A set of node types and the weight of that node type
 * @return int Returns a int
 */
int TreeFactory::GetNodeType(const vector<Vec2i>& weights)
{
	if (weights.size() == 0) throw runtime_error("No weights provided");
	else if (weights.size() == 1) return weights[0][0];

	auto max = 0; for (auto& weight : weights) max += weight[1]; 
	auto value = _generator->Get(0, max);

	auto currentValue = 0;
	for (auto& option : weights) 
	{	
		currentValue += option[1];
		if (currentValue > value) return option[0];
	}

	auto lastIndex = weights.size() - 1;
	return weights[lastIndex][0];
}