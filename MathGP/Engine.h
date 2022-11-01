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

#include <MathGPLib/ArgUtils.h>
#include <MathGPLib/Logger.h>
#include <MathGPLib/Grammar/ScoreUtils.h>
#include <MathGPLib/Grammar/TreeUtils.h>

namespace NVL_App
{
	class Engine
	{
	private:
		NVLib::Parameters * _parameters;
		Logger* _logger;
	public:
		Engine(Logger* logger, NVLib::Parameters * parameters);
		~Engine();

		void Run();
	private:
		inline Logger& Log() { return *_logger; } 
	};
}
