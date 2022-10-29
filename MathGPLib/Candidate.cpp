//--------------------------------------------------
// Implemenation of the candidate
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "Candidate.h"
using namespace NVL_AI;

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
    throw runtime_error("Not Implemented");
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
    throw runtime_error("Not Implemented");
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
     throw runtime_error("Not Implemented");
}
