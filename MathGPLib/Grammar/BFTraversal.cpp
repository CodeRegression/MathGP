//--------------------------------------------------
// Implementation of class BFTraversal
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include "BFTraversal.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param tree The tree that we are traversing
 */
BFTraversal::BFTraversal(Node * tree) : _tree(tree), _position(0)
{
	_layer.push_back(tree);
}

//--------------------------------------------------
// Next
//--------------------------------------------------

/**
 * @brief Retrieve the next node in the tree
 * @return Node * Returns a Node *
 */
Node * BFTraversal::Next()
{
	if (_position >= _layer.size()) UpdateLayer();
	if (_layer.size() == 0) return nullptr;
	return _layer[_position++];
}

//--------------------------------------------------
// Update
//--------------------------------------------------

/**
 * @brief Add the functionality to update the layer
 */
void BFTraversal::UpdateLayer()
{
	auto nextLayer = vector<Node *>();
	
	for (auto node : _layer) 
	{
		for (auto i = 0; i < node->GetChildCount(); i++) 
		{
			nextLayer.push_back(node->GetChild(i));
		}
	}

	_layer = nextLayer; _position = 0;
}