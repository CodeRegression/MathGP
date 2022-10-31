//--------------------------------------------------
// Implementation of class NegateNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "NegateNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param id An identifier for the node
 */
NegateNode::NegateNode(int id) : SingularNode(id)
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
string NegateNode::GetType()
{
	return "NegateNode";
}

/**
 * @brief Retrieve the display name of the node
 * @return string Returns a string
 */
string NegateNode::ToString()
{
	auto result = stringstream();
	result << "(-1 * " << GetChild()->ToString() << ")";
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
double NegateNode::Evaluate(vector<double>& params)
{
	return -1 * GetChild()->Evaluate(params);
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Clone this node
 * @param id The identifier of the new node
 * @return Node * Returns a Node *
 */
Node * NegateNode::Clone(int id)
{
	return new NegateNode(id);
}
