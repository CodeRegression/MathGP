//--------------------------------------------------
// Unit Tests for class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/TreeEncoder.h>
#include <MathGPLib/Grammar/TreeFactory.h>
using namespace NVL_AI;

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
NVL_AI::Node * GetTree(const vector<double>& code);
NVL_AI::Node * Breed(NVL_AI::Node * mother, NVL_AI::Node * father);
NVL_AI::Node * Mutate(NVL_AI::Node * tree, const vector<double>& code);

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test the generation of a random
 */
TEST(TreeFactory_Test, test_generation)
{
	// Setup: Main Players
	auto generator = new NVL_AI::TreeEncoder( vector<double> { 3, 3, 5, 2, 1, 1, 5, 6, 1, 1, 2, 0, 2, 1, 2, 2 } );
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
	auto mother = GetTree( vector<double> { 5, 1, 1, 1, 5, 5, 3, 1, 2, 0, 2, 1, 2, 1 } );
	auto motherCode = mother->ToString();

	// Setup: Father
	auto father = GetTree( vector<double> { 5, 2, 1, 2, 0, 5, 1, 2, 2, 1, 2, 1, 2, 1 } );
	auto fatherCode = father->ToString();

	// Execute
	auto child = Breed(mother, father);
	auto childCode = child->ToString();

	// Confirm
	ASSERT_EQ(motherCode, "(5 + (p[0] * (-1 * p[1])))");
	ASSERT_EQ(fatherCode, "(p[0] - ((1.0 / p[1]) + p[1]))");
	ASSERT_EQ(childCode, "(p[0] + ((1.0 / p[1]) * (-1 * 5)))");

	// Teardown
	delete mother; delete father; delete child;
}

/**
 * @brief Test that the mutation functionality is happening as expected
 */
TEST(TreeFactory_Test, test_mutation) 
{
	// Test 1
	auto tree_1 = GetTree( vector<double> { 5, 1, 5, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 2} );
	ASSERT_EQ(tree_1->ToString(), "((p[1] - (-1 * p[2])) + p[0])");
	auto mtree_1 = Mutate(tree_1, vector<double> { 66 } );
	ASSERT_EQ(mtree_1->ToString(), "((p[1] - (-1 * p[2])) + p[0])");
	delete mtree_1;

	// Test 2
	auto tree_2 = GetTree( vector<double> { 5, 1, 5, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 2} );
	ASSERT_EQ(tree_2->ToString(), "((p[1] - (-1 * p[2])) + p[0])");
	auto mtree_2 = Mutate(tree_2, vector<double> { 10, 0, 3 } );
	ASSERT_EQ(mtree_2->ToString(), "((p[1] - (-1 * p[2])) * p[0])");
	delete mtree_2;

	// Test 3
	auto tree_3 = GetTree( vector<double> { 5, 1, 5, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 2} );
	ASSERT_EQ(tree_3->ToString(), "((p[1] - (-1 * p[2])) + p[0])");
	auto mtree_3 = Mutate(tree_3, vector<double> { 10, 2, 2, 1 } );
	ASSERT_EQ(mtree_3->ToString(), "((p[1] - (-1 * p[2])) + p[1])");
	delete mtree_3;

	// Test 4
	auto tree_4 = GetTree( vector<double> { 5, 1, 5, 2, 1, 2, 0, 1, 2, 1, 2, 1, 2, 2} );
	ASSERT_EQ(tree_4->ToString(), "((p[1] - (-1 * p[2])) + p[0])");
	auto mtree_4 = Mutate(tree_4, vector<double> { 10, 4, 2 } );
	ASSERT_EQ(mtree_4->ToString(), "((p[1] - (1.0 / p[2])) + p[0])");
	delete mtree_4;
}

/**
 * @brief Verify that the algorithm still works if the tree is a "breed" one that involves cloning
 */
TEST(TreeFactory_Test, test_clone_mutation) 
{
	// Setup: Mother
	auto mother = GetTree( vector<double> { 5, 1, 1, 1, 5, 5, 3, 1, 2, 0, 2, 1, 2, 1 } );

	// Setup: Father
	auto father = GetTree( vector<double> { 5, 2, 1, 2, 0, 5, 1, 2, 2, 1, 2, 1, 2, 1 } );

	// Execute
	auto child = Breed(mother, father);
	Mutate(child, vector<double> {10, 1, 2, 2} );
	auto childCode = child->ToString();

	// Confirm
	ASSERT_EQ(childCode, "(p[2] + ((1.0 / p[1]) * (-1 * 5)))");

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
	auto generator = new NVL_AI::TreeEncoder(code);
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
	auto generator = new NVL_AI::TreeEncoder(code);
	auto factory = NVL_AI::TreeFactory(generator, 3, 3, new NVLib::Range<int>(0, 5));
	return factory.Breed(mother, father);
}

/**
 * @brief Add the logic to perform the mutation
 * @param tree The tree that we are mutating
 * @param code The code of the mutation
 * @return NVL_AI::Node The resultant tree
 */
NVL_AI::Node * Mutate(NVL_AI::Node * tree, const vector<double>& code) 
{
	auto generator = new NVL_AI::TreeEncoder(code);
	auto factory = NVL_AI::TreeFactory(generator, 3, 3, new NVLib::Range<int>(0, 5));
	return factory.Mutate(tree, 0.4);
}