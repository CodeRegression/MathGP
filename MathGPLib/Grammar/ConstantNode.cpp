//--------------------------------------------------
// Implementation of class ConstantNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "ConstantNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 * @param inputCount The number of input variables we are expecting
 * @param value The index of the constant that is represented by this node
 */
ConstantNode::ConstantNode(int id, int inputCount, double value) : LeafNode(id, inputCount), _value(value)
{
	// Extra implementation can come here
}

//--------------------------------------------------
// Getters
//--------------------------------------------------

/**
 * @brief Retrieve the type of node
 * @return string Returns a string
 */
string ConstantNode::GetType()
{
	return "ConstantNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string ConstantNode::ToString()
{
	return NVLib::StringUtils::Int2String(_value);
}

//--------------------------------------------------
// Evaluate
//--------------------------------------------------

/**
 * @brief Evaluate the node
 * @param params The input parameters of the given method
 * @return double Returns a double
 */
double ConstantNode::Evaluate(vector<double>& params)
{
	return _value;
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @return Node * Returns a Node *
 */
Node * ConstantNode::Clone()
{
	return new ConstantNode(GetId(), GetInputCount(), _value);
}