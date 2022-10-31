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
	// Setup: Main Players
	auto generator = new NVL_Test::TestGenerator( vector<double> { 3, 3, 5, 2, 1, 1, 5, 6, 1, 1, 2, 0, 2, 1, 2, 2 } );
	auto factory = NVL_AI::TreeFactory(generator, 3, 3, new NVLib::Range<int>(0, 5));

	// Defines the expected result
	auto expected = string("(((p[1] + p[2]) - p[0]) * 5)");

	// Execute
	auto tree = factory.GetRandomTree();
	auto actual = tree->ToString();

	// Confirm
	ASSERT_EQ(actual, expected);

	// Teardown
	delete tree;
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
