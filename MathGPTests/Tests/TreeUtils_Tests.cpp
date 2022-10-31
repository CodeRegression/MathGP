//--------------------------------------------------
// Unit Tests for class TreeUtils
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/AddNode.h>
#include <MathGPLib/Grammar/SubtractNode.h>
#include <MathGPLib/Grammar/MultiplyNode.h>
#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/TreeUtils.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Verify that the code generation is as expected
 */
TEST(TreeUtils_Test, test_code_generation)
{
	// Setup: Expression Tree
	auto node_1 = AddNode(1);
	auto node_2 = new SubtractNode(2);
	auto node_3 = new MultiplyNode(3);
	auto node_4 = new LiteralNode(4, 0);
	auto node_5 = new LiteralNode(5, 1);
	auto node_6 = new LiteralNode(6, 2);
	auto node_7 = new LiteralNode(7, 3);

	node_1.SetChild1(node_2); node_1.SetChild2(node_3);
	node_2->SetChild1(node_4); node_2->SetChild2(node_5);
	node_3->SetChild1(node_6); node_3->SetChild2(node_7);

	// Setup: Expected Reply
	auto expected = stringstream();
	expected << "double Evaluate(vector<double>& p)" << endl;
	expected << "{" << endl;
	expected << "\treturn ((p[0] - p[1]) + (p[2] * p[3]));";
	expected << "}" << endl;

	// Execute
	auto actual = TreeUtils::GetCode(&node_1);

	// Confirm
	ASSERT_EQ(expected.str(), actual);
}

/**
 * @brief Verify that the evaluation of expressions is as expected
 */
TEST(TreeUtils_Test, test_evaluation)
{
	// Setup: Expression Tree
	auto node_1 = AddNode(1);
	auto node_2 = new SubtractNode(2);
	auto node_3 = new MultiplyNode(3);
	auto node_4 = new LiteralNode(4, 0);
	auto node_5 = new LiteralNode(5, 1);
	auto node_6 = new LiteralNode(6, 2);
	auto node_7 = new LiteralNode(7, 3);

	node_1.SetChild1(node_2); node_1.SetChild2(node_3);
	node_2->SetChild1(node_4); node_2->SetChild2(node_5);
	node_3->SetChild1(node_6); node_3->SetChild2(node_7);

	// Setup: parameters
	auto params = vector<double> { 1, 6, 2, 3 };

	// Execute
	auto actual = TreeUtils::Evaluate(&node_1, params);

	// Confirm
	ASSERT_EQ(actual, 1);
}

/**
 * @brief Add persistence functionality
 */
TEST(TreeUtils_Test, test_persistence) 
{
	// Create a population of random nodes

	// Extract the code strings

	// "Save" the population to a writer

	// Clear the current population

	// "Load" the population from a reader

	// Verify that all the code strings are still the same

}