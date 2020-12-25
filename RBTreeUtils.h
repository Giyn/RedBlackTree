/**
 * @filename RBTreeUtils.h
 * @description Red-Black tree utils interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#ifndef RBTREEUTILS_H
#define RBTREEUTILS_H

Status destroy_binary_tree(RBTree tree);

Status preorderBiTree(RBTree tree);

Status inorderBiTree(RBTree tree);

Status postorderBiTree(RBTree tree);

RBTree searchNode(RBTree tree, RBTreeElemType x);

RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right);

#endif /* RBTREEUTILS_H */
