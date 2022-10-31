//--------------------------------------------------
// Unit Tests for class DivideNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/DivideNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(DivideNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 4, 2 };

	// Execute
	auto divideNode = DivideNode(1);
	divideNode.SetChild1(new LiteralNode(2, 0));
	divideNode.SetChild2(new LiteralNode(3, 1));
	auto result = divideNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, 2);
}

/**
 * @brief verify the ToString implementation
 */
TEST(DivideNode_Test, confirm_to_string)
{
	// Execute
	auto divideNode = DivideNode(1);
	divideNode.SetChild1(new LiteralNode(2, 0));
	divideNode.SetChild2(new LiteralNode(3, 1));
	auto value = divideNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(p[0] / p[1])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(DivideNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto divideNode = DivideNode(1);
	divideNode.SetChild1(new LiteralNode(2, 0));
	divideNode.SetChild2(new LiteralNode(3, 1));
	auto cloneNode = divideNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(((DivideNode *)cloneNode)->GetChild1(), nullptr);
	ASSERT_EQ(((DivideNode *)cloneNode)->GetChild2(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
