//--------------------------------------------------
// Unit Tests for class TreeUtils
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/TreeFactory.h>
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
 * @brief Test a controlled encoding
 */
TEST(TreeUtils_Test, test_encoding_1) 
{
	// Generate a tree
	auto encoding_1 = vector<double> { 5, 3, 5, 4, 1, 2, 2, 5, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2 };
	auto tree_1 = TreeUtils::BuildTreeFromEncoding(encoding_1, 30, 3, new NVLib::Range(0, 5));
	auto code_1 = tree_1->ToString();

	// Create a clone from the encoding
	auto encoding_2 = vector<double>(); TreeUtils::GetTreeEncoding(tree_1, encoding_2);
	auto tree_2 = TreeUtils::BuildTreeFromEncoding(encoding_2, 30, 3, new NVLib::Range(0, 5));
	auto code_2 = tree_2->ToString();

	// Comparisons
	ASSERT_EQ(code_1, "(((1 - p[2]) / 1) * p[2])");
	ASSERT_EQ(code_1, code_2);
	ASSERT_EQ(encoding_1.size(), encoding_2.size());

	for (auto i = 0; i < encoding_1.size(); i++) ASSERT_EQ(encoding_1[i], encoding_2[i]);
}

/**
 * @brief Add the logic to test the encoding functionality
 */
TEST(TreeUtils_Test, test_encoding_2) 
{
	// Create a random tree
	auto generator = new RandomGenerator();
	auto factory = TreeFactory(generator, 3, 3, new NVLib::Range(0, 5));
	auto tree = factory.GetRandomTree();

	// Retrieve the code + encoding for the tree
	auto expected = TreeUtils::GetCode(tree);
	auto encoding = vector<double>(); TreeUtils::GetTreeEncoding(tree, encoding);

	// Delete the tree
	delete tree;

	// Rebuild the tree
	tree = TreeUtils::BuildTreeFromEncoding(encoding, 30, 3, new NVLib::Range(0, 5));

	// Confirm that the code of the new tree matches
	auto actual = TreeUtils::GetCode(tree);
	ASSERT_EQ(expected, actual);
}

/**
 * @brief Add persistence functionality
 */
TEST(TreeUtils_Test, test_persistence) 
{
	// Create a population of random nodes
	auto generator = new RandomGenerator(); generator->Initialize();
	auto factory = TreeFactory(generator, 3, 3, new NVLib::Range(0, 5));
	auto population = vector<NVL_AI::Node *>(); for (auto i = 0; i < 500; i++) population.push_back(factory.GetRandomTree());

	// Extract the code strings
	auto codeList = vector<string>(); for (auto& node : population) codeList.push_back(node->ToString());

	// "Save" the population to a writer
	auto readwrite = stringstream(); TreeUtils::SavePopulation(readwrite, population);

	// Clear the current population
	for (auto node : population) delete node; population.clear();

	// "Load" the population from a reader
	TreeUtils::LoadPopulation(readwrite, population);

	// Verify that all the code strings are still the same
	ASSERT_EQ(population.size(), codeList.size());
	for (auto i = 0; i < population.size(); i++) ASSERT_EQ(codeList[i], population[i]->ToString());
}