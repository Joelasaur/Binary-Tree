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

template<typename T>
int BinaryTree<T>::heightHelper(TreeNode<T>* aNode){
	if(aNode == nullptr){
		return 0;
	}
	else{
		int leftHeight = heightHelper(aNode->left);
		int rightHeight= heightHelper(aNode->right);
		return leftHeight > rightHeight
			? leftHeight+1
			: rightHeight+1;
	}
}

template <typename T>
int BinaryTree<T>::height(){
	return heightHelper(this->root);
}

#include "binaryTreeConfig.h"
