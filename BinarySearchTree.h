/**
 * @filename BinarySearchTree.h
 * @description Binary search tree interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#include "RBTree.h"

#ifndef RBTREE_BINARYSEARCHTREE_H
#define RBTREE_BINARYSEARCHTREE_H

/* 二叉查找树插入结点 */
Status insertBinarySearchTree(RBRoot *root, Node *node);

/* 二叉查找树查找最小结点 */
RBTree minBinarySearchTreeNode(RBTree tree);

/* 二叉查找树查找最大结点 */
RBTree maxBinarySearchTreeNode(RBTree tree);

/* 二叉查找树查找前驱结点 */
RBTree BSTreePrecursor(RBTree node);

/* 二叉查找树查找后继结点 */
RBTree BSTreeSuccessor(RBTree node);

#endif //RBTREE_BINARYSEARCHTREE_H
