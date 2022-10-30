//--------------------------------------------------
// Unit Tests for class ConstantNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/ConstantNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(ConstantNode_Test, confirm_evaluate)
{
	// Setup
	auto params = vector<double> { 1, 2, 3, 4 };		

	// Execute
	auto node = ConstantNode(1, 4, 88);
	auto value = node.Evaluate(params);

	// Confirm
	ASSERT_EQ(value, 88);
}

/**
 * @brief verify the ToString implementation
 */
TEST(ConstantNode_Test, confirm_to_string)
{
	// Execute
	auto node = ConstantNode(1, 4, 88);
	auto value = node.ToString();

	// Confirm
	ASSERT_EQ(value, "88");
}

/**
 * @brief Verify the clone implementation
 */
TEST(ConstantNode_Test, confirm_clone)
{
	// Setup
	auto params = vector<double> { 1,2, 3, 4 };		

	// Execute
	auto node = ConstantNode(1, 4, 88);
	auto cloneNode = node.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(node.GetInputCount(), cloneNode->GetInputCount());
	ASSERT_EQ(node.Evaluate(params), cloneNode->Evaluate(params));

	// Teardown
	delete cloneNode;
}
