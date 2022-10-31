//--------------------------------------------------
// Implementation of class MultiplyNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "MultiplyNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 */
MultiplyNode::MultiplyNode(int id) : BinaryNode(id)
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
string MultiplyNode::GetType()
{
	return "MultiplyNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string MultiplyNode::ToString()
{
	auto result = stringstream();
	result << "(" << GetChild1()->ToString() << " * " << GetChild2()->ToString() << ")";
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
double MultiplyNode::Evaluate(vector<double>& params)
{
	auto value1 = GetChild1()->Evaluate(params);
	auto value2 = GetChild2()->Evaluate(params);
	return value1 * value2;
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the new node
 * @return Node * Returns a Node *
 */
Node * MultiplyNode::Clone(int id)
{
	return new MultiplyNode(id);
}

//--------------------------------------------------
// Update Code
//--------------------------------------------------

/**
 * @brief The code that we are updating
 * @param code The code that we are adding 
 */
void MultiplyNode::UpdateCode(vector<double>& code) 
{
	code.push_back(5); code.push_back(3);
}