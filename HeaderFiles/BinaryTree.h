/**
 * @filename BinaryTree.h
 * @description Binary tree interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#include "RedBlackTree.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

/* 销毁二叉树 */
Status destroyBinaryTree(RBTree tree);

/* 前序遍历二叉树 */
Status preorderBiTree(RBTree tree);

/* 中序遍历二叉树 */
Status inorderBiTree(RBTree tree);

/* 后序遍历二叉树 */
Status postorderBiTree(RBTree tree);

/* 查找结点 */
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x);

#endif /* BINARYTREE_H */
