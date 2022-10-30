//--------------------------------------------------
// Implementation of class LiteralNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "LiteralNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 * @param inputCount The number of input elements we are expecting
 * @param index The index of the literal that we are using
 */
LiteralNode::LiteralNode(int id, int inputCount, int index) : LeafNode(id, inputCount), _index(index)
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
string LiteralNode::GetType()
{
	return string("LiteralNode");
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string LiteralNode::ToString()
{
	auto result = stringstream(); result << "p[" << _index << "]";
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
double LiteralNode::Evaluate(vector<double>& params)
{
	return params[_index];
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @return Node * Returns a Node *
 */
Node * LiteralNode::Clone()
{
	return new LiteralNode(GetId(), GetInputCount(),_index);
}