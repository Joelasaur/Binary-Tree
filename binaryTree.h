#ifndef BINARYTREE_H
#define BINARYTREE_H

template <typename T>
struct TreeNode{
	struct TreeNode<T> *left;
	struct TreeNode<T> *right;
	T value;
	TreeNode(T newValue);
	TreeNode(T newValue, TreeNode<T> *leftNode, TreeNode<T> *rightNode);
};

// typedef void (*pfnv)(TreeNode<T> *node);
template <typename T>
using pfnv = void (*)(TreeNode<T> *node);

template <typename T>
class BinaryTree{
private:
	TreeNode<T> *root;
	int heightHelper(TreeNode<T>* aNode);
public:
	BinaryTree(TreeNode<T> *aNode);
	bool isEmpty();
	int height(void);
	void preOrder(pfnv<T> visitor);
	void inOrder(pfnv<T> visitor);
	void postOrder(pfnv<T> visitor);
};
#endif
