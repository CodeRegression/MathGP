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
 * @param value The index of the constant that is represented by this node
 */
ConstantNode::ConstantNode(int id, double value) : LeafNode(id), _value(value)
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
	auto result = stringstream(); result << setprecision(3) << fixed << _value;
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
double ConstantNode::Evaluate(vector<double>& params)
{
	return _value;
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the node that we are cloning
 * @return Node * Returns a Node *
 */
Node * ConstantNode::Clone(int id)
{
	return new ConstantNode(id, _value);
}

//--------------------------------------------------
// Update Code
//--------------------------------------------------

/**
 * @brief Add the code to the system 
 * @param code The code that we are adding
 */
void ConstantNode::UpdateEncoding(vector<double>& code) 
{
	code.push_back(1); code.push_back(1); code.push_back(int(_value * 100));
}