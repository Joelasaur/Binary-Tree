#ifndef BINARYTREE_H
#define BINARYTREE_H
template <class T>
  struct TreeNode{
    struct TreeNode left;
    struct TreeNode right;
    T value;
    TreeNode(T newValue);
    TreeNode(T newValue, TreeNode<T> leftNode, TreeNode<T> rightNode);
  };





#endif
