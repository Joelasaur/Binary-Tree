#include "gtest/gtest.h"
#include "binaryTree.h"
#include <string.h>

TEST(TreeNodeTest, testConstructors){
	TreeNode <int> *node1 = new TreeNode<int>(5);
	TreeNode <int> *node2 = new TreeNode<int>(6);
	TreeNode <int> *node3 = new TreeNode<int>(7, node1, node2);

	EXPECT_EQ(node1->value, 5);
	EXPECT_EQ(node2->value, 6);
	EXPECT_EQ(node3->value, 7);
	EXPECT_EQ(node3->left, node1);
	EXPECT_EQ(node3->right, node2);
}

int treeSpec[]={1,2,-3,1,-4,0};
BinaryTree<int>* treeBuilder(int* treeData){
	std::stack<TreeNode<int> *> nodeStack; 

} 

TEST(BinaryTreeTest, testConstructor){
	BinaryTree<int> *aTree = new BinaryTree<int>(nullptr);
	EXPECT_TRUE(aTree->isEmpty());
}


TEST(BinaryTreeTest, testHeight){
        BinaryTree<int> *aTree = new BinaryTree<int>(nullptr);
	EXPECT_EQ(aTree->height(),0);
}

TEST(BinaryTreeTest, testPostOrder){
	EXPECT_TRUE(false);
}

TEST(BinaryTreeTest, testPreOrder){
	EXPECT_TRUE(false);
}

TEST(BinaryTreeTest, testInOrder){
	EXPECT_TRUE(false);
}


