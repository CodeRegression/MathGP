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
// Perform Random Generation
//--------------------------------------------------

/**
 * @brief Generates a pure random solution
 * @param id The identifier of the element that we are generating
 * @return CandidateBase* The candidate that we are generating
 */
CandidateBase * CandidateFactory::PerformRandomGeneration(int id)
{
    throw runtime_error("Not Implemented");
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
    throw runtime_error("Not Implemented");
}
