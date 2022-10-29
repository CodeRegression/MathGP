//--------------------------------------------------
// Implementation of class ArgUtils
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include "ArgUtils.h"
using namespace NVL_App;

//--------------------------------------------------
// Load Parameters
//--------------------------------------------------

/**
 * @brief Load parameters
 * @param appName The name of the application
 * @param argc The number of incomming parameter arguments
 * @param argv The incomming variables
 * @return NVLib::Parameters * Returns a NVLib::Parameters *
 */
NVLib::Parameters * ArgUtils::Load(const string& appName, int argc, char ** argv)
{
	if (argc > 2) throw runtime_error(NVLib::Formatter() << "Usage: " << appName << " <config.xml>");
	auto configPath = argc == 1 ? string("config.xml") : string(argv[1]);
	return NVLib::ParameterLoader::Load(configPath);
}
