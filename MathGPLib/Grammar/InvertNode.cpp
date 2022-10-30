//--------------------------------------------------
// Implementation of class InvertNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "InvertNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 * @param inputCount The number of input elements that we have
 */
InvertNode::InvertNode(int id, int inputCount) : SingularNode(id, inputCount)
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
string InvertNode::GetType()
{
	return "InvertNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string InvertNode::ToString()
{
	auto result = stringstream();
	result << "(1.0 / " << GetChild()->ToString() << ")";
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
double InvertNode::Evaluate(vector<double>& params)
{
	return 1.0 / GetChild()->Evaluate(params);
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the new node
 * @return Node * Returns a Node *
 */
Node * InvertNode::Clone(int id)
{
	return new InvertNode(id, GetInputCount());
}
