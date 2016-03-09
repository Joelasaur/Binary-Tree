#include "binaryTree.h"

template <typename T>
TreeNode<T>::TreeNode(T newValue){
	this->value = newValue;
	this->left = 0;
	this->right = 0;
}

template <typename T>
TreeNode<T>::TreeNode(T newValue, TreeNode<T> *leftNode, TreeNode<T> *rightNode){
	this->value = newValue;
	this->left = leftNode;
	this->right = rightNode;
}

template <typename T>
BinaryTree<T>::BinaryTree(TreeNode<T> * aNode){
	this->root = aNode;
}

template <typename T>
bool BinaryTree<T>::isEmpty(){
	return !this->root;
}

#include "binaryTreeConfig.h"
