//--------------------------------------------------
// Unit Tests for class InvertNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/InvertNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(InvertNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 4, 2 };

	// Execute
	auto invertNode = InvertNode(1, 2);
	invertNode.SetChild(new LiteralNode(2, 2, 0));
	auto result = invertNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, 0.25);
}

/**
 * @brief verify the ToString implementation
 */
TEST(InvertNode_Test, confirm_to_string)
{
	// Execute
	auto invertNode = InvertNode(1, 2);
	invertNode.SetChild(new LiteralNode(2, 2, 0));
	auto value = invertNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(1.0 / p[0])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(InvertNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto invertNode = InvertNode(1, 2);
	invertNode.SetChild(new LiteralNode(2, 2, 0));
	auto cloneNode = invertNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(cloneNode->GetInputCount(), 2);
	ASSERT_EQ(((InvertNode *)cloneNode)->GetChild(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
