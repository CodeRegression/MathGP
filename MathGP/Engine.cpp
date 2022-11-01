//--------------------------------------------------
// Implementation code for the Engine
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "Engine.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructor and Terminator
//--------------------------------------------------

/**
 * Main Constructor
 * @param logger The logger that we are using for the system
 * @param parameters The input parameters
 */
Engine::Engine(Logger* logger, NVLib::Parameters* parameters) 
{
    _logger = logger; _parameters = parameters;
}

/**
 * Main Terminator 
 */
Engine::~Engine() 
{
    delete _parameters;
}

//--------------------------------------------------
// Execution Entry Point
//--------------------------------------------------

/**
 * Entry point function
 */
void Engine::Run()
{
    Log() << "Loading problem file" << Logger::End();
    auto path = ArgUtils::GetString(_parameters, "arff");
    auto fieldNames = vector<string>();
    Mat testCases = NVL_AI::ScoreUtils::LoadARFF(path, fieldNames);

    Log() << "Building a solution tree" << Logger::End();
    auto encoding = vector<double> { 5, 2, 5, 3, 1, 2, 2, 1, 2, 0, 1, 2, 1 };
    auto solution = NVL_AI::TreeUtils::BuildTreeFromEncoding(encoding, 100, fieldNames.size(), new NVLib::Range<int>(-5, 5));
    Log() << "Solution Tree: " << solution->ToString() << Logger::End();

    Log() << "Get the score for the solution" << Logger::End();
    auto score = NVL_AI::ScoreUtils::Evaluate(testCases, solution);
    Log() << "Final Score: " << score << Logger::End();
}
