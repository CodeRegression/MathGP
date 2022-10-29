//--------------------------------------------------
// Implementation of the logic to find the score
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <NVLib/Formatter.h>
#include <GeneticLib/Utility/ScoreFinderBase.h>
#include "Candidate.h"

namespace NVL_AI
{
	class ScoreFinder : public ScoreFinderBase
	{
	public:
		virtual double GetScore(CandidateBase * candidate) override;		
        virtual bool ProblemSolved(CandidateBase * candidate) override;
	};
}
