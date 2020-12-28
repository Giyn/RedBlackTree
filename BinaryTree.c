/**
 * @filename BinaryTree.c
 * @description Binary tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

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
RBTree recursiveSearchNode(RBTree tree, RBTreeElemType x) {
    if (!tree || tree->data == x) return tree;
    else if (tree->data > x) return recursiveSearchNode(tree->left, x);
    else return recursiveSearchNode(tree->right, x);
}
