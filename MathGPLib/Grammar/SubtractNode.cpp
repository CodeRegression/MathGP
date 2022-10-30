//--------------------------------------------------
// Implementation of class SubtractNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "SubtractNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 * @param inputCount The number of input elements that we have
 */
SubtractNode::SubtractNode(int id, int inputCount) : BinaryNode(id, inputCount)
{
	// Extract implementation codes here
}

//--------------------------------------------------
// Getters
//--------------------------------------------------

/**
 * @brief Retrieve the type of node
 * @return string Returns a string
 */
string SubtractNode::GetType()
{
	return "SubtractNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string SubtractNode::ToString()
{
	auto result = stringstream();
	result << "(" << GetChild1()->ToString() << " - " << GetChild2()->ToString() << ")";
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
double SubtractNode::Evaluate(vector<double>& params)
{
	auto value1 = GetChild1()->Evaluate(params);
	auto value2 = GetChild2()->Evaluate(params);
	return value1 - value2;
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the node that we are subtracting
 * @return Node * Returns a Node *
 */
Node * SubtractNode::Clone(int id)
{
	return new SubtractNode(id, GetInputCount());
}
