/**
 * @filename RBTreeUtils.c
 * @description Red-Black tree utils interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

/**
 * 销毁二叉树
 *
 * @param[in]  tree  the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status destroyBinaryTree(RBTree tree) {
    if (!tree) return ERROR;

    if (tree->left) destroyBinaryTree(tree->left);
    if (tree->right) destroyBinaryTree(tree->right);

    free(tree);

    return OK;
}

/**
 * 前序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status preorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        printf("%d ", tree->data);
        preorderBiTree(tree->left);
        preorderBiTree(tree->right);
    }

    return OK;
}

/**
 * 中序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status inorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        inorderBiTree(tree->left);
        printf("%d ", tree->data);
        inorderBiTree(tree->right);
    }

    return OK;
}

/**
 * 后序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status postorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        postorderBiTree(tree->left);
        postorderBiTree(tree->right);
        printf("%d ", tree->data);
    }

    return OK;
}

/**
 * 递归查找二叉树tree中数据域为x的结点
 *
 * @param[in]  tree: the node of the binary tree
 * @param[in]  x   : the data of the node
 * @return  the target node
 */
RBTree searchNode(RBTree tree, RBTreeElemType x) {
    if (!tree || tree->data == x) return tree;
    else if (tree->data > x) return searchNode(tree->left, x);
    else return searchNode(tree->right, x);
}

/**
 * 创建红黑树结点
 *
 * @param[in]  x     : the data of the node
 * @param[in]  parent: its parent node
 * @param[in]  left  : its left child node
 * @param[in]  right : its right child node
 * @return  the new red-black tree node pointer
 */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right) {
    RBTree node = (Node *) malloc(sizeof(Node));
    if (!node) return NULL;

    node->data = x;
    node->left = left;
    node->right = right;
    node->parent = parent;
    node->color = BLACK;

    return node;
}

/**
 * 将红黑树的结点node左旋
 *
 * 示例: 对结点1左旋
 *        1                 3
 *      /  \              /  \
 *     2    3    -->     1    5
 *        /  \         /  \
 *       4    5       2    4
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the node of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status RBTreeLeftRotate(RBRoot *root, Node *node) {
    Node *p = node->right;

    if (p->left) {
        node->right = p->left;
        p->left->parent = node;
    } else node->right = NULL;

    p->parent = node->parent;

    if (!node->parent) root->node = p;
    else {
        if (node->parent->left == node) node->parent->left = p;
        else node->parent->right = p;
    }

    p->left = node;
    node->parent = p;
}

/**
 * 将红黑树的结点node右旋
 *
 * 示例: 对结点1右旋
 *        1                 2
 *      /  \              /  \
 *     2    3    -->     4    1
 *   /  \                   /  \
 *  4    5                 5    3
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the node of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status RBTreeRightRotate(RBRoot *root, Node *node) {
    Node *p = node->left;

    if (p->right) {
        node->left = p->right;
        p->right->parent = node;
    } else node->right = NULL;

    p->parent = node->parent;

    if (!node->parent) root->node = p;
    else {
        if (node == node->parent->right) node->parent->right = p;
        else node->parent->left = p;
    }

    p->right = node;
    node->parent = p;
}
