/**
 * @filename RBTreeUtils.c
 * @description Red-Black tree utils interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"
#include "RBTree.c"

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
 *        1            2
 *      /  \         /  \
 *     2    3  -->  4    1
 *   /  \              /  \
 *  4    5            5    3
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

/**
 * 红黑树插入后自平衡
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the inserted node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node) {
    Node *parent, *grandparent;

    /* 父结点为红色结点 */
    while ((parent = RBTreeParent(node)) && RBTreeIsRed(parent)) {
        grandparent = RBTreeParent(parent);

        /* 父结点是祖父结点的左孩子结点” */
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;

            /* 叔叔结点是红色结点 */
            if (uncle && RBTreeIsRed(uncle)) {
                RBTreeSetBlack(parent);
                RBTreeSetBlack(uncle);
                RBTreeSetRed(grandparent);
                node = grandparent;
                continue;
            }

            /* 叔叔结点不存在, 且插入结点是其父结点的左孩子结点 */
            if (node == parent->left) {
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                RBTreeRightRotate(root, grandparent);
            }

            /* 叔叔结点不存在, 且插入结点是其父结点的右孩子结点 */
            if (node == parent->right) {
                Node *temp;
                RBTreeLeftRotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
            }
        } else { /* 父结点是祖父结点的右孩子结点” */
            Node *uncle = grandparent->left;

            /* 叔叔结点是红色结点 */
            if (uncle && RBTreeIsRed(uncle)) {
                RBTreeSetBlack(uncle);
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                node = grandparent;
                continue;
            }

            /* 叔叔结点不存在, 且插入结点是其父结点的右孩子结点 */
            if (node == parent->right) {
                RBTreeSetBlack(parent);
                RBTreeSetRed(grandparent);
                RBTreeLeftRotate(root, grandparent);
            }

            /* 叔叔结点不存在, 且插入结点是其父结点的左孩子结点 */
            if (node == parent->left) {
                Node *temp;
                RBTreeRightRotate(root, parent);
                temp = parent;
                parent = node;
                node = temp;
            }
        }
    }

    RBTreeSetBlack(root->node);

    return OK;
}

/**
 * 二叉查找树插入结点
 *
 * @param[in]  root: the root of the binary search tree
 * @param[in]  node: the inserted node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status insertBinarySearchTree(RBRoot *root, Node *node) {
    Node *p = root->node, *last;

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
 * 红黑树查找最小结点
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  minVal: the minimum value of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal) {
    Node *node = NULL;

    if (root) node = minBinarySearchTreeNode(root->node);
    if (!node) return ERROR;

    *minVal = node->data;

    return OK;
}
