//--------------------------------------------------
// Adds `mutations` to candidate solutions
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <GeneticLib/Utility/MutationBase.h>

#include "Candidate.h"

namespace NVL_AI
{
	class Mutation : public MutationBase
	{
    public:
        virtual void Mutate(CandidateBase * candidate) override;
	};
}
