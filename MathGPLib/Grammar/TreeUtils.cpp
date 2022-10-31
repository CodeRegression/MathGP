//--------------------------------------------------
// Implementation of class TreeUtils
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include "TreeUtils.h"
using namespace NVL_AI;

//--------------------------------------------------
// Code
//--------------------------------------------------

/**
 * @brief Generate the code for a tree
 * @param tree The tree that we are generating the code from
 * @return string Returns a string
 */
string TreeUtils::GetCode(Node * tree)
{
	auto result = stringstream();
	
	result << "double Evaluate(vector<double>& p)" << endl;
	result << "{" << endl;
	result << "\treturn " << tree->ToString() << ";";
	result << "}" << endl;

	return result.str();
}

//--------------------------------------------------
// Evaluate
//--------------------------------------------------

/**
 * @brief Evaluate the tree wrt a set of inputs
 * @param tree The tree that we are evaluating
 * @param params The parameters that we are using for the evaluation
 * @return double Returns a double
 */
double TreeUtils::Evaluate(Node * tree, vector<double>& params)
{
	return tree->Evaluate(params);
}