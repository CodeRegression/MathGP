//--------------------------------------------------
// Defines a factory for generating candidate solutions
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "Candidate.h"
#include <GeneticLib/Utility/CandidateFactoryBase.h>

namespace NVL_AI
{
	class CandidateFactory : public CandidateFactoryBase
	{
	public:
        CandidateFactory(ScoreFinderBase * scoreFinder, MutationBase * mutator) : CandidateFactoryBase(scoreFinder, mutator) {} 
    protected:
		virtual CandidateBase * PerformRandomGeneration(int id) override;
        virtual CandidateBase * PerformBreedGeneration(int id, CandidateBase * parent1, CandidateBase * parent2) override; 
	};
}
