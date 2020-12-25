/**
 * @filename RBTree.c
 * @description Red-Black tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RBTree.h"
#include "RBTreeUtils.h"

#define rb_color(r) ((r)->color)
#define rb_parent(r) ((r)->parent)
#define rb_is_red(r) ((r)->color == RED)
#define rb_is_black(r) ((r)->color == BLACK)
#define rb_set_color(r, c) do {(r)->color = (c);} while(0)
#define rb_set_parent(r, p) do {(r)->parent = (p);} while(0)
#define rb_set_red(r) do {(r)->color = RED;} while(0)
#define rb_set_black(r) do {(r)->color = BLACK;} while(0)

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
 * 递归查找红黑树tree中数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status searchRBTree(RBRoot *root, RBTreeElemType x) {
    if (root) return searchNode(root->node, x) ? OK : ERROR;
}
