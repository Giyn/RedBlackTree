/**
 * @filename RedBlackTree.c
 * @description Red-Black tree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "../HeaderFiles/RedBlackTree.h"
#include "../HeaderFiles/RedBlackTreeUtils.h"
#include "../HeaderFiles/BinarySearchTree.h"
#include "../HeaderFiles/BinaryTree.h"

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
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status destroyRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else destroyBinaryTree(root->node);

    free(root);

    return SUCCESS;
}

/**
 * 前序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status preorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else preorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 中序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status inorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else inorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 后序遍历红黑树
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status postorderRBTree(RBRoot *root)
{
    if (!root) return FAILED;
    else postorderBiTree(root->node);

    return SUCCESS;
}

/**
 * 递归查找红黑树tree中数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status recursiveSearchRBTree(RBRoot *root, RBTreeElemType x)
{
    if (root) return recursiveSearchNode(root->node, x) ? SUCCESS : FAILED;
}

/**
 * 红黑树插入数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  x   : the data of the node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status insertRBTree(RBRoot *root, RBTreeElemType x)
{
    if (recursiveSearchNode(root->node, x)) return FAILED;

    Node *node;
    node = createRBTreeNode(x, NULL, NULL, NULL);
    if (!node) return FAILED;

    insertBinarySearchTree(root, node);
    RBTreeInsertSelfBalancing(root, node);

    return SUCCESS;
}

/**
 * 红黑树删除数据域为x的结点
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  key : the data of the node to be deleted
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status deleteRBTree(RBRoot *root, RBTreeElemType x)
{
    Node *p;
    if (p = recursiveSearchNode(root->node, x)) {
        deleteRBTreeNode(root, p);
        return SUCCESS;
    }

    return FAILED;
}

/**
 * 打印红黑树信息
 *
 * @param[in]  root: the root of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status printRBTree(RBRoot *root)
{
    if (root && root->node) {
        PrintRBTreeInfo(root->node, root->node->data, 0);
        return SUCCESS;
    }

    return FAILED;
}
