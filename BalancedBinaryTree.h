/**
 * @filename BalancedBinaryTree.c
 * @description balanced binary tree interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#include "RedBlackTree.h"

#ifndef BALANCEDBINARYTREE_H
#define BALANCEDBINARYTREE_H

/* 平衡二叉树结点左旋 */
Status RBTreeLeftRotate(RBRoot *root, Node *node);

/* 平衡二叉树结点右旋 */
Status RBTreeRightRotate(RBRoot *root, Node *node);

#endif /* BALANCEDBINARYTREE_H */
