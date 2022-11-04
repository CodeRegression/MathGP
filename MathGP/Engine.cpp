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

    auto server = ArgUtils::GetString(parameters, "server");
    auto port = ArgUtils::GetString(parameters, "port");
    _machine = ArgUtils::GetString(parameters, "machine");

    _codeDash = new NVL_AI::CodeDash(server, port);

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
    delete _parameters; delete _candidateFactory; delete _treeFactory; delete _codeDash;
}

//--------------------------------------------------
// Execution Entry Point
//--------------------------------------------------

/**
 * Entry point function
 */
void Engine::Run()
{
    Log() << "Loading Parameters" << Logger::End();
    auto populationSize = ArgUtils::GetInteger(_parameters, "population");
    auto sampleSize = ArgUtils::GetInteger(_parameters, "sample");
    auto iterationCount = ArgUtils::GetInteger(_parameters, "iteration"); 

    Log() << "Creating a session" << Logger::End();
    auto sessionId = _codeDash->CreateSession("MP_1", "FIT_0000", _machine);
    Log() << "Created session: " << sessionId << Logger::End();

    Log() << "Creating a runner" << Logger::End();
    auto runner = NVL_AI::GeneticRunner(_candidateFactory, populationSize, sampleSize);
    runner.SetLogger(new NVL_AI::DashLogger(sessionId, _codeDash));

    // Launch the search
    runner.Run(iterationCount);
}
