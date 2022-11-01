//--------------------------------------------------
// Utility: A factory type utility for generating new candidates
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "CandidateFactory.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructor and Terminator
//--------------------------------------------------

/**
 * @brief Main Constructor
 * @param scoreFinder Defines the logic to find the score
 * @param mutator Defines the logic to find the mutator
 * @param factory The current tree factory
 */
CandidateFactory::CandidateFactory(ScoreFinderBase * scoreFinder, MutationBase * mutator, TreeFactory * factory) : CandidateFactoryBase(scoreFinder, mutator), _factory(factory)
{
    // Extra initialization comes here
}

//--------------------------------------------------
// Perform Random Generation
//--------------------------------------------------

/**
 * @brief Generates a pure random solution
 * @param id The identifier of the element that we are generating
 * @return CandidateBase* The candidate that we are generating
 */
CandidateBase * CandidateFactory::PerformRandomGeneration(int id)
{
    auto newTree = _factory->GetRandomTree();
    return new Candidate(id, newTree);
}

//--------------------------------------------------
// Perform Breed Generation
//--------------------------------------------------

/**
 * @brief Generate a candidate using the "breeding" process
 * @param id The identifier of the element that we are generating
 * @param parent1 The first parent
 * @param parent2 The second parent
 * @return CandidateBase* The generated child from the process
 */
CandidateBase * CandidateFactory::PerformBreedGeneration(int id, CandidateBase * parent1, CandidateBase * parent2) 
{
    auto mother = ((Candidate *) parent1)->GetTree();
    auto father = ((Candidate *) parent2)->GetTree();

    auto newTree = _factory->Breed(mother, father);

    return new Candidate(id, newTree);
}