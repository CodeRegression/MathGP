//--------------------------------------------------
// Unit Tests for class MultiplyNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/MultiplyNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(MultiplyNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 2, 3 };

	// Execute
	auto multiplyNode = MultiplyNode(1);
	multiplyNode.SetChild1(new LiteralNode(2, 0));
	multiplyNode.SetChild2(new LiteralNode(3, 1));
	auto result = multiplyNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, 6);
}

/**
 * @brief verify the ToString implementation
 */
TEST(MultiplyNode_Test, confirm_to_string)
{
	// Execute
	auto multiplyNode = MultiplyNode(1);
	multiplyNode.SetChild1(new LiteralNode(2, 0));
	multiplyNode.SetChild2(new LiteralNode(3, 1));
	auto value = multiplyNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(p[0] * p[1])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(MultiplyNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto multiplyNode = MultiplyNode(1);
	multiplyNode.SetChild1(new LiteralNode(2, 0));
	multiplyNode.SetChild2(new LiteralNode(3, 1));
	auto cloneNode = multiplyNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(((MultiplyNode *)cloneNode)->GetChild1(), nullptr);
	ASSERT_EQ(((MultiplyNode *)cloneNode)->GetChild2(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
