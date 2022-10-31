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

//--------------------------------------------------
// Persistence
//--------------------------------------------------

/**
 * @brief Save a tree populate to a writer
 * @param writer The writer that we are using 
 * @param population The population that we are saving
 */
void TreeUtils::SavePopulation(ostream& writer, vector<Node *>& population) 
{
	throw runtime_error("Not Implemented");
}

/**
 * @brief Load a tree population from a writer
 * @param reader The reader that we are using 
 * @param population The population that we have generated
 */
void TreeUtils::LoadPopulation(istream& reader, vector<Node *>& population) 
{
	throw runtime_error("Not Implemented");
}