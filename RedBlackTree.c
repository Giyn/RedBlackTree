/**
 * @filename RedBlackTree.c
 * @description Red-Black tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"
#include "RedBlackTreeUtils.h"
#include "BinaryTree.h"

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
    else destroyBinaryTree(root->node);

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
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x) {
    if (root) return recursiveSearchNode(root->node, x) ? OK : ERROR;
}

/**
 * 红黑树插入数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x) {
    if (recursiveSearchNode(root->node, x)) return ERROR;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return ERROR;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return OK;
}

/**
 * 红黑树删除数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  key : the data of the node to be deleted
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status deleteRBTree(RBRoot *root, RBTreeElemType x) {
    Node *p;
    if (p = recursiveSearchNode(root->node, x)) deleteRBTreeNode(root, p);
}
