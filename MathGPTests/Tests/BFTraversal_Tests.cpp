//--------------------------------------------------
// Unit Tests for class BFTraversal
//
// @author: Wild Boar
//
// @date: 2022-10-31
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathGPLib/Grammar/AddNode.h>
#include <MathGPLib/Grammar/NegateNode.h>
#include <MathGPLib/Grammar/ConstantNode.h>
#include <MathGPLib/Grammar/BFTraversal.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that the traversal is working correctly
 */
TEST(BFTraversal_Test, test_traversal)
{
	// Setup
	auto node_1 = AddNode(1, 2);
	auto node_2 = new AddNode(2, 2);
	auto node_3 = new NegateNode(3, 2);
	auto node_4 = new ConstantNode(4, 2, 0.5);
	auto node_5 = new ConstantNode(5, 2, 0.6);
	auto node_6 = new NegateNode(6, 2);
	auto node_7 = new ConstantNode(7, 2, 0.8);

	node_1.SetChild1(node_2); node_1.SetChild2(node_3);
	node_2->SetChild1(node_4); node_2->SetChild2(node_5);
	node_3->SetChild(node_6);
	node_6->SetChild(node_7);

	// Execute
	auto traversal = BFTraversal(&node_1);

	// Confirm
	ASSERT_EQ(traversal.Next()->GetId(), 1);
	ASSERT_EQ(traversal.Next()->GetId(), 2);
	ASSERT_EQ(traversal.Next()->GetId(), 3);
	ASSERT_EQ(traversal.Next()->GetId(), 4);
	ASSERT_EQ(traversal.Next()->GetId(), 5);
	ASSERT_EQ(traversal.Next()->GetId(), 6);
	ASSERT_EQ(traversal.Next()->GetId(), 7);
}