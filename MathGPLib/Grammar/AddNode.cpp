//--------------------------------------------------
// Implementation of class AddNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "AddNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 */
AddNode::AddNode(int id) : BinaryNode(id)
{
	// Extra implementation can go here
}

//--------------------------------------------------
// Getters
//--------------------------------------------------

/**
 * @brief Retrieve the type of node
 * @return string Returns a string
 */
string AddNode::GetType()
{
	return "AddNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string AddNode::ToString()
{
	auto result = stringstream();
	result << "(" << GetChild1()->ToString() << " + " << GetChild2()->ToString() << ")";
	return result.str();
}

//--------------------------------------------------
// Evaluate
//--------------------------------------------------

/**
 * @brief Evaluate the node
 * @param params The input parameters of the given method
 * @return double Returns a double
 */
double AddNode::Evaluate(vector<double>& params)
{
	auto value1 = GetChild1()->Evaluate(params);
	auto value2 = GetChild2()->Evaluate(params);
	return value1 + value2;
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the node that we are cloning
 * @return Node * Returns a Node *
 */
Node * AddNode::Clone(int id)
{
	return new AddNode(id);
}