/**
 * @filename rbtree.c
 * @description RBTree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

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
RBRoot *create_rbtree() {
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
Status destroy_rbtree(RBRoot *root) {
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
static Status preorder(RBTree tree) {
    if (!tree) return ERROR;
    else {
        printf("%d ", tree->key);
        preorder(tree->left);
        preorder(tree->right);
    }

    return OK;
}

/**
 * 前序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status preorder_rbtree(RBRoot *root) {
    if (!root) return ERROR;
    else preorder(root->node);

    return OK;
}

/**
 * 中序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status inorder(RBTree tree) {
    if (!tree) return ERROR;
    else {
        inorder(tree->left);
        printf("%d ", tree->key);
        inorder(tree->right);
    }

    return OK;
}

/**
 * 中序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status inorder_rbtree(RBRoot *root) {
    if (!root) return ERROR;
    else inorder(root->node);

    return OK;
}

/**
 * 后序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
static Status postorder(RBTree tree) {
    if (!tree) return ERROR;
    else {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->key);
    }

    return OK;
}

/**
 * 后序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status postorder_rbtree(RBRoot *root) {
    if (!root) return ERROR;
    else postorder(root->node);

    return OK;
}
