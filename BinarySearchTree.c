/**
 * @filename BinarySearchTree.c
 * @description Binary search tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include "BinarySearchTree.h"

/**
 * 二叉查找树插入结点
 *
 * @param[in]  root: the root of the binary search tree
 * @param[in]  node: the inserted node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status insertBinarySearchTree(RBRoot *root, Node *node) {
    Node *p = root->node;
    Node *last = NULL;

    while (p) {
        last = p;
        if (node->data < p->data) p = p->left;
        else p = p->right;
    }
    RBTreeParent(node) = last;

    if (last) {
        if (node->data < last->data) last->left = node;
        else last->right = node;
    } else root->node = node;

    node->color = RED;

    return OK;
}

/**
 * 二叉查找树查找最小结点
 *
 * @param[in]  tree: the root of the binary search tree
 * @return  the minimum node of the binary search tree
 */
RBTree minBinarySearchTreeNode(RBTree tree) {
    if (!tree) return NULL;

    while (tree->left) tree = tree->left;

    return tree;
}

/**
 * 二叉查找树查找最大结点
 *
 * @param[in]  tree: the root of the binary search tree
 * @return  the maximum node of the binary search tree
 */
RBTree maxBinarySearchTreeNode(RBTree tree) {
    if (!tree) return NULL;

    while (tree->right) tree = tree->right;

    return tree;
}

/**
 * 二叉查找树查找结点node的前驱结点
 *
 * @param[in]  node: the node to be found its precursor
 * @return  the target precursor node
 */
RBTree BSTreePrecursor(RBTree node) {
    if (node->left) return maxBinarySearchTreeNode(node->left);

    Node *p = node->parent;
    while (p && (node == p->left)) {
        node = p;
        p = p->parent;
    }

    return p;
}

/**
 * 二叉查找树查找结点node的后继结点
 *
 * @param[in]  node: the node to be found its successor
 * @return  the target successor node
 */
RBTree BSTreeSuccessor(RBTree node) {
    if (node->right) return minBinarySearchTreeNode(node->right);

    Node *p = node->parent;
    while (p && (node == p->right)) {
        node = p;
        p = p->parent;
    }

    return p;
}
