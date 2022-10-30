//--------------------------------------------------
// Unit Tests for class LiteralNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(LiteralNode_Test, confirm_evaluate)
{
	// Setup
	auto params = vector<double> { 1,2, 3, 4 };		

	// Execute
	auto node = LiteralNode(1, 4, 1);
	auto value = node.Evaluate(params);

	// Confirm
	ASSERT_EQ(value, 2);
}

/**
 * @brief verify the ToString implementation
 */
TEST(LiteralNode_Test, confirm_to_string)
{
	// Execute
	auto node = LiteralNode(1, 4, 1);
	auto value = node.ToString();

	// Confirm
	ASSERT_EQ(value, "p[1]");
}

/**
 * @brief Verify the clone implementation
 */
TEST(LiteralNode_Test, confirm_clone)
{
	// Setup
	auto params = vector<double> { 1,2, 3, 4 };		

	// Execute
	auto node = LiteralNode(1, 4, 1);
	auto cloneNode = node.Clone();

	// Confirm
	ASSERT_EQ(node.GetId(), cloneNode->GetId());
	ASSERT_EQ(node.GetInputCount(), cloneNode->GetInputCount());
	ASSERT_EQ(node.Evaluate(params), cloneNode->Evaluate(params));

	// Teardown
	delete cloneNode;
}