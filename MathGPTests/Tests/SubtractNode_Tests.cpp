//--------------------------------------------------
// Unit Tests for class SubtractNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/SubtractNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(SubtractNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 2, 3 };

	// Execute
	auto subtractNode = SubtractNode(1);
	subtractNode.SetChild1(new LiteralNode(2, 0));
	subtractNode.SetChild2(new LiteralNode(3, 1));
	auto result = subtractNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, -1);
}

/**
 * @brief verify the ToString implementation
 */
TEST(SubtractNode_Test, confirm_to_string)
{
	// Execute
	auto subtractNode = SubtractNode(1);
	subtractNode.SetChild1(new LiteralNode(2, 0));
	subtractNode.SetChild2(new LiteralNode(3, 1));
	auto value = subtractNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(p[0] - p[1])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(SubtractNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto subtractNode = SubtractNode(1);
	subtractNode.SetChild1(new LiteralNode(2, 0));
	subtractNode.SetChild2(new LiteralNode(3, 1));
	auto cloneNode = subtractNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(((SubtractNode *)cloneNode)->GetChild1(), nullptr);
	ASSERT_EQ(((SubtractNode *)cloneNode)->GetChild2(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
