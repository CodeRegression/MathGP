//--------------------------------------------------
// Implementation of the logic to find the score
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "ScoreFinder.h"
using namespace NVL_AI;

//--------------------------------------------------
// GetScore
//--------------------------------------------------

/**
 * @brief Main Constructor
 * @param testCases The test cases that we are going to test against
 */
ScoreFinder::ScoreFinder(Mat& testCases) : _testCases(testCases)
{
    // Extra initialization can go here
}

//--------------------------------------------------
// GetScore
//--------------------------------------------------

/**
 * @brief Calculate the score associated with a given candidate
 * @param candidate The candidate that we are calculating the score for
 * @return double The score as a double
 */
double ScoreFinder::GetScore(CandidateBase * candidate)
{
    return ScoreUtils::Evaluate(_testCases, ((Candidate*) candidate)->GetTree());
}

//--------------------------------------------------
// Problem Solved
//--------------------------------------------------

/**
 * @brief Check to see if our proposed solution to the problem is "optimal"
 * @param candidate The solution that we are checking
 * @return true It is an optimal solution (no need to continue searching for a better one)
 * @return false There is still room for improvement
 */
bool ScoreFinder::ProblemSolved(CandidateBase * candidate)
{
    auto score = ScoreUtils::Evaluate(_testCases, ((Candidate*) candidate)->GetTree());
    return abs(score) < 1e-4;
}
