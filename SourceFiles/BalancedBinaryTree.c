/**
 * @filename BalancedBinaryTree.c
 * @description Balanced binary tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include "../HeaderFiles/BalancedBinaryTree.h"

/**
 * 将平衡二叉树的结点node左旋
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
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeLeftRotate(RBRoot *root, Node *node)
{
    Node *p = node->right;
    node->right = p->left;

    if (p->left) p->left->parent = node;

    p->parent = node->parent;

    if (!node->parent) root->node = p;
    else {
        if (node->parent->left == node) node->parent->left = p;
        else node->parent->right = p;
    }

    p->left = node;
    node->parent = p;

    return SUCCESS;
}

/**
 * 将平衡二叉树的结点node右旋
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
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeRightRotate(RBRoot *root, Node *node)
{
    Node *p = node->left;
    node->left = p->right;

    if (p->right) p->right->parent = node;

    p->parent = node->parent;

    if (!node->parent) root->node = p;
    else {
        if (node == node->parent->right) node->parent->right = p;
        else node->parent->left = p;
    }

    p->right = node;
    node->parent = p;

    return SUCCESS;
}
