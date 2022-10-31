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
	auto firstNodeType = GetNodeType(vector<Vec2i> { Vec2i(2, 1), Vec2i(3, 9)} );
	auto root = firstNodeType == 1 ? GetRandomSingularNode(id++) : GetRandomBinaryNode(id++);
	current.push_back(root);

	// Add random children
	while (current.size() > 0) 
	{
		for (auto i = 0; i < current.size(); i++) 
		{
			auto node = current[i];

			for (auto childId = 0; childId < node->GetChildCount(); childId++) 
			{
				auto weights = (_depthLimit >= level++) ? vector<Vec2i> { Vec2i(1, 1), Vec2i(2,2), Vec2i(3, 7)} : vector<Vec2i> { Vec2i(1,1)};
				auto nodeTypeId = GetNodeType(weights);
				auto child = GetRandomNode(nodeTypeId, id++);
				node->SetChild(childId, child); next.push_back(child);
			}
		}

		current.clear(); 
		for (auto i = 0; i < next.size(); i++) current.push_back(next[i]); 
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
	// Create a variable to hold the id counter
	auto id = 0;

	// Create the parsers
	auto motherParser = BFTraversal(mother);
	auto fatherParser = BFTraversal(father);

	// Setup the level vectors
	auto current = vector<NVL_AI::Node *>(); auto next = vector<NVL_AI::Node *>();

	// Create the root node
	auto root_1 = motherParser.Next();
	auto root_2 = fatherParser.Next();
	auto rootSelectId = _generator->Get(0, 1);
	auto root = rootSelectId == 0 ? root_1->Clone(id++) : root_2->Clone(id++);
	current.push_back(root);

	// Add children until there are none to add
	while (current.size() > 0) 
	{
		for (auto i = 0; i < current.size(); i++) 
		{
			auto node = current[i];

			for (auto childId = 0; childId < node->GetChildCount(); childId++) 
			{
				// Get the next nodes in the parse list
				auto node_1 = motherParser.Next(); auto node_2 = fatherParser.Next();

				// Generate the next nodes
				Node * newNode = nullptr;
				if (node_1 == nullptr && node_2 != nullptr) newNode = node_2->Clone(id++);
				else if (node_1 != nullptr && node_2 == nullptr) newNode = node_1->Clone(id++);
				else if (node_1 != nullptr && node_2 != nullptr) 
				{
					auto selectId = _generator->Get(0, 1);
					newNode = selectId == 0 ? node_1->Clone(id++) : node_2->Clone(id++);
				}
				else newNode = GetRandomLeafNode(id);	
				
				// Update the child
				node->SetChild(childId, newNode); next.push_back(newNode);
			}
		}

		// Update the current
		current.clear();
		for (auto node : next) current.push_back(node);
		next.clear();
	}

	// return the result
	return root;
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
	auto nodeId = _generator->Get(1, 2);

	if (nodeId == 1) 
	{
		auto value = _generator->Get(_constantRange->GetMin(), _constantRange->GetMax());
		return new ConstantNode(id, value);
	}
	else if (nodeId == 2)
	{
		auto index = _generator->Get(0, _inputCount);
		return new LiteralNode(id, index);
	}
	else throw runtime_error("Unknown Leaf Node");
}

/**
 * @brief Retrieve a random binary node
 * @param id The node identifier
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomBinaryNode(int id)
{
	auto nodeId = _generator->Get(1, 4);
	if (nodeId == 1) return new AddNode(id);
	else if (nodeId == 2) return new SubtractNode(id);
	else if (nodeId == 3) return new MultiplyNode(id);
	else if (nodeId == 4) return new DivideNode(id);
	else throw runtime_error("Unknown Binary node");
}

/**
 * @brief Retrieve a random singular node
 * @param id The node identifier
 * @return Node * Returns a Node *
 */
NVL_AI::Node * TreeFactory::GetRandomSingularNode(int id)
{
	auto nodeId = _generator->Get(1, 2);
	if (nodeId == 1) return new NegateNode(id);
	else if (nodeId == 2) return new InvertNode(id);
	else throw runtime_error("Uknown singular node");
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
		if (currentValue >= value) return option[0];
	}

	auto lastIndex = weights.size() - 1;
	return weights[lastIndex][0];
}