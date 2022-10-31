//--------------------------------------------------
// Unit Tests for class NegateNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/NegateNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(NegateNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 4, 2 };

	// Execute
	auto negateNode = NegateNode(1);
	negateNode.SetChild(new LiteralNode(2, 0));
	auto result = negateNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, -4);
}

/**
 * @brief verify the ToString implementation
 */
TEST(NegateNode_Test, confirm_to_string)
{
	// Execute
	auto negateNode = NegateNode(1);
	negateNode.SetChild(new LiteralNode(2, 0));
	auto value = negateNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(-1 * p[0])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(NegateNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto negateNode = NegateNode(1);
	negateNode.SetChild(new LiteralNode(2, 0));
	auto cloneNode = negateNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(((NegateNode *)cloneNode)->GetChild(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
