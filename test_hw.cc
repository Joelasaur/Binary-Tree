#include "gtest/gtest.h"
#include "binaryTree.h"
#include <string.h>
#include <stack>

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

int treeSpec[]={1,2,-3,9,-4,0};
BinaryTree<int>* treeBuilder(int* treeData){
	std::stack<TreeNode<int> *> nodeStack;
	int* nextIntRef = treeData;
	while(*nextIntRef != 0){
		TreeNode<int> *node;
		if(*nextIntRef > 0){
			node = new TreeNode<int>(*nextIntRef);
		}
		else{
			TreeNode<int> *right = nodeStack.top();
			nodeStack.pop();
			TreeNode<int> *left = nodeStack.top();
			nodeStack.pop();
			node = new TreeNode<int>(*nextIntRef, left, right);
		}
		nodeStack.push(node);
		nextIntRef++;
	}
	return new BinaryTree<int> (nodeStack.top());
}

TEST(BinaryTreeTest, testConstructor){
	BinaryTree<int> *aTree = new BinaryTree<int>(nullptr);
	EXPECT_TRUE(aTree->isEmpty());
	aTree = treeBuilder(treeSpec);
	EXPECT_FALSE(aTree->isEmpty());
}


TEST(BinaryTreeTest, testHeight){
  BinaryTree<int> *aTree = new BinaryTree<int>(nullptr);
	EXPECT_EQ(aTree->height(),0);
	aTree = treeBuilder(treeSpec);
	EXPECT_EQ(aTree->height(),3);
}

static int visitedNodes[5];
static int index;
void visitNode(TreeNode<int>* aNode){
	visitedNodes[index] = aNode->value;
	index++;
}

TEST(BinaryTreeTest, testPostOrder){
	index = 0;
	BinaryTree<int> *aTree = treeBuilder(treeSpec);
	aTree->postOrder(visitNode);
	EXPECT_EQ(visitedNodes[0],1);
	EXPECT_EQ(visitedNodes[1],2);
	EXPECT_EQ(visitedNodes[2],-3);
	EXPECT_EQ(visitedNodes[3],9);
	EXPECT_EQ(visitedNodes[4],-4);
}

TEST(BinaryTreeTest, testPreOrder){
	index = 0;
	BinaryTree<int> *aTree = treeBuilder(treeSpec);
	aTree->preOrder(visitNode);
	EXPECT_EQ(visitedNodes[0],-4);
	EXPECT_EQ(visitedNodes[1],-3);
	EXPECT_EQ(visitedNodes[2],1);
	EXPECT_EQ(visitedNodes[3],2);
	EXPECT_EQ(visitedNodes[4],9);
}

TEST(BinaryTreeTest, testInOrder){
	index = 0;
	BinaryTree<int> *aTree = treeBuilder(treeSpec);
	aTree->inOrder(visitNode);
	EXPECT_EQ(visitedNodes[0],1);
	EXPECT_EQ(visitedNodes[1],-3);
	EXPECT_EQ(visitedNodes[2],2);
	EXPECT_EQ(visitedNodes[3],-4);
	EXPECT_EQ(visitedNodes[4],9);
}
