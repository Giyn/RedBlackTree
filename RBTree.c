/**
 * @filename RBTree.c
 * @description RBTree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"

#define rb_color(r) ((r)->color)
#define rb_parent(r) ((r)->parent)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)

/**
 * 创建红黑树
 *
 * @param[in]  none
 * @return  the root of the red-black tree
 */
RBRoot *createRBTree() {
    RBRoot *root = (RBRoot *) malloc(sizeof(RBRoot));
    root->node = NULL;

    return root;
}

/**
 * 销毁二叉树
 *
 * @param[in]  tree  the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status destroy_binary_tree(RBTree tree) {
    if (!tree) return ERROR;

    if (tree->left) destroy_binary_tree(tree->left);
    if (tree->right) destroy_binary_tree(tree->right);

    free(tree);

    return OK;
}

/**
 * 销毁红黑树
 *
 * @param[in]  root  the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status destroyRBTree(RBRoot *root) {
    if (!root) return ERROR;
    else destroy_binary_tree(root->node);

    free(root);

    return OK;
}


/**
 * 前序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status preorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        printf("%d ", tree->data);
        preorderBiTree(tree->left);
        preorderBiTree(tree->right);
    }

    return OK;
}

/**
 * 前序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status preorderRBTree(RBRoot *root) {
    if (!root) return ERROR;
    else preorderBiTree(root->node);

    return OK;
}

/**
 * 中序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status inorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        inorderBiTree(tree->left);
        printf("%d ", tree->data);
        inorderBiTree(tree->right);
    }

    return OK;
}

/**
 * 中序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status inorderRBTree(RBRoot *root) {
    if (!root) return ERROR;
    else inorderBiTree(root->node);

    return OK;
}

/**
 * 后序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status postorderBiTree(RBTree tree) {
    if (!tree) return ERROR;
    else {
        postorderBiTree(tree->left);
        postorderBiTree(tree->right);
        printf("%d ", tree->data);
    }

    return OK;
}

/**
 * 后序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status postorderRBTree(RBRoot *root) {
    if (!root) return ERROR;
    else postorderBiTree(root->node);

    return OK;
}

/**
 * 递归查找二叉树tree中数据域为x的结点
 *
 * @param[in]  tree: the node of the binary tree
 * @param[in]  x   : the data of the node
 * @return  the target node
 */
static Node *search(RBTree tree, RBTreeElemType x) {
    if (!tree || tree->data == x) return tree;
    else if (tree->data > x) return search(tree->left, x);
    else return search(tree->right, x);
}

/**
 * 递归查找红黑树tree中数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status searchRBTree(RBRoot *root, RBTreeElemType x) {
    if (root) return search(root->node, x) ? OK : ERROR;
}
