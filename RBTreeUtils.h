/**
 * @filename RBTreeUtils.h
 * @description Red-Black tree utils interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#ifndef RBTREEUTILS_H
#define RBTREEUTILS_H

/* 销毁二叉树 */
Status destroyBinaryTree(RBTree tree);

/* 前序遍历二叉树 */
Status preorderBiTree(RBTree tree);

/* 中序遍历二叉树 */
Status inorderBiTree(RBTree tree);

/* 后序遍历二叉树 */
Status postorderBiTree(RBTree tree);

/* 查找结点 */
RBTree searchNode(RBTree tree, RBTreeElemType x);

/* 创建红黑树结点 */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right);

/* 红黑树结点左旋 */
Status RBTreeLeftRotate(RBRoot *root, Node *node);

/* 红黑树结点右旋 */
Status RBTreeRightRotate(RBRoot *root, Node *node);

/* 二叉查找树插入结点 */
Status insertBinarySearchTree(RBRoot *root, Node *node);

/* 红黑树插入结点后自平衡 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node);

/* 二叉查找树查找最小结点 */
RBTree minBinarySearchTreeNode(RBTree tree);

/* 红黑树查找最小结点 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal);

#endif /* RBTREEUTILS_H */
