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

#include "Grammar/Node.h"
#include "Grammar/TreeUtils.h"
#include "Grammar/TreeFactory.h"

#include <GeneticLib/Model/CandidateBase.h>

namespace NVL_AI
{
	class Candidate : public CandidateBase
	{
	private:
        NVL_AI::Node * _tree;
    public:
		Candidate(int id, NVL_AI::Node * tree);
        ~Candidate();

        virtual bool Equals(CandidateBase * candidate) override;
        virtual string ToString() override;
        virtual CandidateBase * Clone() override;

        inline NVL_AI::Node * GetTree() { return _tree; }
        inline void SetTree(NVL_AI::Node * tree) { _tree = tree; }
    };
}