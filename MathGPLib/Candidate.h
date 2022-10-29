//--------------------------------------------------
// Model: A candidate solution for this test case
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <GeneticLib/Model/CandidateBase.h>

namespace NVL_AI
{
	class Candidate : public CandidateBase
	{
	private:
        // TODO: Add in values
    public:
		Candidate(int id) : CandidateBase(id, 0) {}

        virtual bool Equals(CandidateBase * candidate) override;
        virtual string ToString() override;
        virtual CandidateBase * Clone() override;
    };
}
