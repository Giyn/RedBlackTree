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
 * @return  none
 */
static void destroy_binary_tree(RBTree tree) {
    if (!tree) return;

    if (tree->left) destroy_binary_tree(tree->left);
    if (tree->right) destroy_binary_tree(tree->right);

    free(tree);
}

/**
 * 销毁红黑树
 *
 * @param[in]  root  the root of the red-black tree
 * @return  none
 */
void destroy_rbtree(RBRoot *root) {
    if (root) destroy_binary_tree(root->node);

    free(root);
}


/**
 * 前序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  none
 */
static void preorder(RBTree tree) {
    if (tree) {
        printf("%d ", tree->key);
        preorder(tree->left);
        preorder(tree->right);
    }
}

/**
 * 前序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  none
 */
void preorder_rbtree(RBRoot *root) {
    if (root) preorder(root->node);
}

/**
 * 中序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  none
 */
static void inorder(RBTree tree) {
    if (tree) {
        inorder(tree->left);
        printf("%d ", tree->key);
        inorder(tree->right);
    }
}

/**
 * 中序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  none
 */
void inorder_rbtree(RBRoot *root) {
    if (root) inorder(root->node);
}

/**
 * 后序遍历二叉树
 *
 * @param[in]  tree: the node of the binary tree
 * @return  none
 */
static void postorder(RBTree tree) {
    if (tree) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->key);
    }
}

/**
 * 后序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  none
 */
void postorder_rbtree(RBRoot *root) {
    if (root) postorder(root->node);
}
