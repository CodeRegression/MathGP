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
    auto generator = new NVL_AI::RandomGenerator(); generator->Initialize();

    auto problemPath = ArgUtils::GetString(parameters, "arff");
    auto depthLimit = ArgUtils::GetInteger(parameters, "depth_limit");
    auto constMin = ArgUtils::GetInteger(parameters, "const_min");
    auto constMax = ArgUtils::GetInteger(parameters, "const_max");
    auto mProbability = ArgUtils::GetDouble(parameters, "mutation");

    auto fieldNames = vector<string>(); Mat testCases = NVL_AI::ScoreUtils::LoadARFF(problemPath, fieldNames);
    
    _treeFactory = new NVL_AI::TreeFactory(generator, depthLimit, fieldNames.size(), new NVLib::Range(constMin, constMax));

    auto scoreFinder = new NVL_AI::ScoreFinder(testCases);
    auto mutator = new NVL_AI::Mutation(_treeFactory, mProbability);

    _candidateFactory = new NVL_AI::CandidateFactory(scoreFinder, mutator, _treeFactory); 
}

/**
 * Main Terminator 
 */
Engine::~Engine() 
{
    delete _parameters; delete _candidateFactory; delete _treeFactory;
}

//--------------------------------------------------
// Execution Entry Point
//--------------------------------------------------

/**
 * Entry point function
 */
void Engine::Run()
{

}
