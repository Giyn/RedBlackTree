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
#include "BinarySearchTree.h"
#include "BinaryTree.h"

/**
 * 创建红黑树
 *
 * @param[in]  none
 * @return  the root of the red-black tree
 */
RBRoot *createRBTree()
{
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
Status destroyRBTree(RBRoot *root)
{
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
Status preorderRBTree(RBRoot *root)
{
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
Status inorderRBTree(RBRoot *root)
{
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
Status postorderRBTree(RBRoot *root)
{
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
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x)
{
    if (root) return recursiveSearchNode(root->node, x) ? OK : ERROR;
}

/**
 * 红黑树插入数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
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
Status deleteRBTree(RBRoot *root, RBTreeElemType x)
{
    Node *p;
    if (p = recursiveSearchNode(root->node, x)) {
        deleteRBTreeNode(root, p);
        return OK;
    }

    return ERROR;
}

/**
 * 红黑树信息的打印
 *
 * @param[in]  tree    : the node of the red-black tree
 * @param[in]  data    : the data of the node
 * @param[in]  position: 0 - the current node is the root node
 *                      -1 - the current node is the left child node
 *                       1 - the current node is the right child node
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position) {
    if (tree) {
        if (position == 0) printf("[%d](BLACK)是根节点\n", tree->data);
        else printf("[%d](%s)是[%d]的%s孩子结点\n", tree->data, RBTreeIsRed(tree) ? "RED" : "BLACK",
                    data, position == -1 ? "左" : "右");

        PrintRBTreeInfo(tree->left, tree->data, -1);
        PrintRBTreeInfo(tree->right, tree->data, 1);

        return OK;
    }

    return ERROR;
}

/**
 * 打印红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, OK is 0, ERROR is -1
 */
Status printRBTree(RBRoot *root) {
    if (root && root->node) {
        PrintRBTreeInfo(root->node, root->node->data, 0);
        return OK;
    }

    return ERROR;
}
