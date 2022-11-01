//--------------------------------------------------
// Implementation of the mutation logic
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "Mutation.h"
using namespace NVL_AI;

//--------------------------------------------------
// Mutate
//--------------------------------------------------

/**
 * @brief Main Constructor
 * @param factory The factory that we are working with
 * @param probability The associated probability
 */
Mutation::Mutation(TreeFactory * factory, double probability) : _factory(factory), _probability(probability)
{
    // Extra initialization can go here
}

//--------------------------------------------------
// Mutate
//--------------------------------------------------

/**
 * @brief Add the logic to perform mutation
 * @param candidate The candidate that we are mutating
 */
void Mutation::Mutate(CandidateBase * candidate)
{
    auto alias = (Candidate *) candidate;
    auto tree = _factory->Mutate(alias->GetTree(), _probability);
    alias->SetTree(tree);
}
