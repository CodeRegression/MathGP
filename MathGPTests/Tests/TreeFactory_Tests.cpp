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
// Function Prototypes
//--------------------------------------------------
NVL_AI::Node * GetTree(const vector<double>& code);
NVL_AI::Node * Breed(NVL_AI::Node * mother, NVL_AI::Node * father);

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
	// Setup: Mother
	auto mother = GetTree( vector<double> { 5, 1, 1, 1, 5, 5, 3, 1, 2, 0, 2, 1, 1, 2, 1 } );
	auto motherCode = mother->ToString();

	// Setup: Father
	auto father = GetTree( vector<double> { 5, 2, 1, 2, 0, 5, 1, 2, 2, 1, 2, 1, 1, 2, 1 } );
	auto fatherCode = father->ToString();

	// Execute
	auto child = Breed(mother, father);
	auto childCode = child->ToString();

	// Confirm
	ASSERT_EQ(motherCode, "(5 + (p[0] * (-1 * p[1])))");
	ASSERT_EQ(fatherCode, "(p[0] - ((1.0 / p[1]) + p[1]))");
	ASSERT_EQ(childCode, "(p[0] + ((1.0 / p[1]) * (-1 * 5))");

	// Teardown
	delete mother; delete father; delete child;
}

//--------------------------------------------------
// Utility Methods
//--------------------------------------------------

/**
 * @brief Retrieve the given tree
 * @param code The code that we are getting
 * @return The node that we have generated
 */
NVL_AI::Node * GetTree(const vector<double>& code) 
{
	auto generator = new NVL_Test::TestGenerator(code);
	auto factory = NVL_AI::TreeFactory(generator, 3, 3, new NVLib::Range<int>(0, 5));
	return factory.GetRandomTree();
}

/**
 * @brief Add the functionality to perform breeding
 * @param mother The mother node that we are working with
 * @param father The father node that we are working with
 * @return The resultant child node
 */
NVL_AI::Node * Breed(NVL_AI::Node * mother, NVL_AI::Node * father)
{
	auto code = vector<double> { 0, 1, 0, 1, 0, 1, 1, 5 };
	auto generator = new NVL_Test::TestGenerator(code);
	auto factory = NVL_AI::TreeFactory(generator, 3, 3, new NVLib::Range<int>(0, 5));
	return factory.Breed(mother, father);
}