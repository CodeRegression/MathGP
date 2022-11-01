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
// Encoding Helpers
//--------------------------------------------------

/**
 * @brief Retrieve the encodings that make up a tree
 * @param tree The tree that we are getting the encodings for
 * @param encoding The encodings that we are using
 */
void TreeUtils::GetTreeEncoding(Node * tree, vector<double>& encoding) 
{
	auto traversal = BFTraversal(tree); encoding.clear(); Node * node = nullptr;
	
	do 
	{
		node = traversal.Next();
		if (node != nullptr) node->UpdateEncoding(encoding);
	} 
	while (node != nullptr);
}

/**
 * @brief Build a given tree from encodings
 * @param encoding The encoding that we are getting for the tree
 * @param depthLimit The depth limit of the tree
 * @param inputCount The input count of the tree
 * @param constantRange The constant range of the tree
 * @return The tree that we have generated
 */
NVL_AI::Node * TreeUtils::BuildTreeFromEncoding(const vector<double>& encoding, int depthLimit, int inputCount, NVLib::Range<int>* constantRange) 
{
	auto encoder = new TreeEncoder(encoding);
	auto factory = TreeFactory(encoder, depthLimit, inputCount, constantRange);
	return factory.GetRandomTree();
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
	for (auto node : population) 
	{
		auto encoding = vector<double>(); GetTreeEncoding(node, encoding);
		writer << encoding.size();
		for (auto& value : encoding) writer << " " << value; writer << endl;
	}
}

/**
 * @brief Load a tree population from a writer
 * @param reader The reader that we are using 
 * @param population The population that we have generated
 */
void TreeUtils::LoadPopulation(istream& reader, vector<Node *>& population) 
{
	// Make sure that the population is clear
	population.clear();

	// Loop thru the entries and add new elements
	while (true) 
	{
		int size; reader >> size;
		if (!reader.good()) break;

		auto encoding = vector<double>();
		for (auto i = 0; i < size; i++) 
		{
			int value; reader >> value;
			encoding.push_back(value);
		}

		auto node = BuildTreeFromEncoding(encoding, 100, 100, new NVLib::Range(0, 1));
		population.push_back(node);
	}
}