//--------------------------------------------------
// Implementation of the candidate
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "Candidate.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructor and Terminator
//--------------------------------------------------

/**
 * @brief Main constructor
 * @param id The candidate identifier
 * @param tree The tree that we are getting values for
 */
Candidate::Candidate(int id, NVL_AI::Node * tree) : CandidateBase(id, 0), _tree(tree)
{
    // Extra implementation can go here
}

/**
 * @brief Main Terminator
 */
Candidate::~Candidate() 
{
    delete _tree;
}

//--------------------------------------------------
// Equality Check
//--------------------------------------------------

/**
 * @brief Equality check
 * @param candidate The candidate we are checking
 * @return true They are equal
 * @return false They are not equal
 */
bool Candidate::Equals(CandidateBase * candidate)
{
    auto code_1 = _tree->ToString();
    auto code_2 = ((Candidate *)candidate)->_tree->ToString();
    return code_1 == code_2;
}

//--------------------------------------------------
// ToString
//--------------------------------------------------

/**
 * @brief Converts the solution to a string
 * @return string A string representation of the solution
 */
string Candidate::ToString() 
{
    return _tree->ToString();
}

//--------------------------------------------------
// Clone
//--------------------------------------------------

/**
 * @brief Add the logic to clone a solution
 * @return CandidateBase* The cloned version of this solution
 */
CandidateBase * Candidate::Clone()
{
    auto id = GetId();
    auto encoding = vector<double>(); _tree->Evaluate(encoding);
    auto newTree = TreeUtils::BuildTreeFromEncoding(encoding, INT_MAX, INT_MAX, new NVLib::Range<int>(0, 1));
    return new Candidate(id, newTree);
}
