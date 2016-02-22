#include "gtest/gtest.h"
#include "binaryTree.h"
#include <string.h>

TEST(TreeNodeTest, testConstructors){
	TreeNode <int> node1 = new TreeNode(5);
	TreeNode <int> node2 = new TreeNode(6);
	TreeNode <int> node3 = new TreeNode<int>(7, node1, node2);

	EXPECT_EQ(node1->value, 5);
	EXPECT_EQ(node2->value, 6);
	EXPECT_EQ(node3->value, 7);
	EXPECT_EQ(node3->left, node1);
	EXPECT_EQ(node3->right, node2);
}
