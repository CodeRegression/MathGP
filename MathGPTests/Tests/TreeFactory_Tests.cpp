//--------------------------------------------------
// Unit Tests for class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/TreeFactory.h>
using namespace NVL_AI;

#include "../Helpers/TestGenerator.h"

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test the generation of a random
 */
TEST(TreeFactory_Test, test_generation)
{
	// Setup
	auto generator = NVL_Test::TestGenerator( vector<double> {3,3,3,2,1,5,3,1,2,0,1,2} );

	// Execute
	//auto tree = NVL_AI

	// Confirm

	// Teardown
}

/**
 * @brief Test the breeding operation
 */
TEST(TreeFactory_Test, test_breeding)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}
