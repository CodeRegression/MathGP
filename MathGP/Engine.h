//--------------------------------------------------
// Defines a basic engine for a vanilla C++ project.
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/Logger.h>

#include <GeneticLib/Utility/GeneticRunner.h>

#include <MathGPLib/ArgUtils.h>
#include <MathGPLib/Logger.h>
#include <MathGPLib/DashLogger.h>

#include <MathGPLib/CandidateFactory.h>
#include <MathGPLib/ScoreFinder.h>
#include <MathGPLib/Mutation.h>

#include <MathGPLib/Grammar/TreeFactory.h>
#include <MathGPLib/Grammar/ScoreUtils.h>
#include <MathGPLib/Grammar/TreeUtils.h>

namespace NVL_App
{
	class Engine
	{
	private:
		NVLib::Parameters * _parameters;
		Logger* _logger; NVL_AI::CodeDash * _codeDash;
		NVL_AI::TreeFactory * _treeFactory;
		NVL_AI::CandidateFactory * _candidateFactory;
		string _machine;
	public:
		Engine(Logger* logger, NVLib::Parameters * parameters);
		~Engine();

		void Run();
	private:
		inline Logger& Log() { return *_logger; } 
	};
}
