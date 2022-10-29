//--------------------------------------------------
// Handle incoming arguments
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/Formatter.h>
#include <NVLib/Parameters/ParameterLoader.h>

namespace NVL_App
{
	class ArgUtils
	{
	public:
		static NVLib::Parameters * Load(const string& appName, int argc, char ** argv);
	};
}
