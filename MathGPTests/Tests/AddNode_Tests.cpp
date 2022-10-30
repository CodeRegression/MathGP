//--------------------------------------------------
// Unit Tests for class AddNode
//
// @author: Wild Boar
//
// @date: 2022-10-30
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/LiteralNode.h>
#include <MathGPLib/Grammar/AddNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm correct operation of the evaluate functionality
 */
TEST(AddNode_Test, confirm_evaluate)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto addNode = AddNode(1, 2);
	addNode.SetChild1(new LiteralNode(2, 2, 0));
	addNode.SetChild2(new LiteralNode(3, 2, 1));
	auto result = addNode.Evaluate(input);

	// Confirm
	ASSERT_EQ(result, 4);
}

/**
 * @brief verify the ToString implementation
 */
TEST(AddNode_Test, confirm_to_string)
{
	// Execute
	auto addNode = AddNode(1, 2);
	addNode.SetChild1(new LiteralNode(2, 2, 0));
	addNode.SetChild2(new LiteralNode(3, 2, 1));
	auto value = addNode.ToString();

	// Confirm
	ASSERT_EQ(value, "(p[0] + p[1])");
}

/**
 * @brief Verify the clone implementation
 */
TEST(AddNode_Test, confirm_clone)
{
	// Setup
	auto input = vector<double> { 2, 2 };

	// Execute
	auto addNode = AddNode(1, 2);
	addNode.SetChild1(new LiteralNode(2, 2, 0));
	addNode.SetChild2(new LiteralNode(3, 2, 1));
	auto cloneNode = addNode.Clone(5);

	// Confirm
	ASSERT_EQ(cloneNode->GetId(), 5);
	ASSERT_EQ(cloneNode->GetInputCount(), 2);
	ASSERT_EQ(((AddNode *)cloneNode)->GetChild1(), nullptr);
	ASSERT_EQ(((AddNode *)cloneNode)->GetChild2(), nullptr);

	// Teardown Logic
	delete cloneNode;
}
