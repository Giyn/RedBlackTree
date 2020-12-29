/**
 * @filename RedBlackTreeUtils.c
 * @description Red-Black tree utils interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "RedBlackTree.h"
#include "BinarySearchTree.h"
#include "BalancedBinaryTree.h"

/**
 * 创建红黑树结点
 *
 * @param[in]  x     : the data of the node
 * @param[in]  parent: its parent node
 * @param[in]  left  : its left child node
 * @param[in]  right : its right child node
 * @return  the new red-black tree node pointer
 */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right)
{
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
 * 红黑树插入结点后自平衡
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the inserted node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node)
{
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

    return SUCCESS;
}

/**
 * 红黑树查找最小结点
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  minVal: the minimum value of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal)
{
    Node *node = NULL;

    if (root) node = minBinarySearchTreeNode(root->node);
    if (!node) return FAILED;

    *minVal = node->data;

    return SUCCESS;
}

/**
 * 红黑树查找最大结点
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  maxVal: the maximum value of the red-black tree
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status maxRBTreeNode(RBRoot *root, RBTreeElemType *maxVal)
{
    Node *node = NULL;

    if (root) node = maxBinarySearchTreeNode(root->node);
    if (!node) return FAILED;

    *maxVal = node->data;

    return SUCCESS;
}

/**
 * 红黑树删除结点后自平衡
 *
 * @param[in]  root  : the root of the red-black tree
 * @param[in]  node  : the deleted node
 * @param[in]  parent: the deleted node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent)
{
    Node *sibling = NULL;

    while ((!node || RBTreeIsBlack(node)) && node != root->node) {
        if (node == parent->left) {
            sibling = parent->right;
            /* node的兄弟结点sibling是红色结点 */
            if (RBTreeIsRed(sibling)) {
                RBTreeSetBlack(sibling);
                RBTreeSetRed(parent);
                RBTreeLeftRotate(root, parent);
                sibling = parent->right;
            }
            /* node的兄弟结点sibling是黑色结点, sibling的2个孩子结点都是黑色结点 */
            if ((!sibling->left || RBTreeIsBlack(sibling->left)) &&
                (!sibling->right || RBTreeIsBlack(sibling->right))) {
                RBTreeSetRed(sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node的兄弟结点sibling是黑色结点, sibling的左孩子是红色, 右孩子是黑色 */
                if (!sibling->right || RBTreeIsBlack(sibling->right)) {
                    RBTreeSetRed(sibling);
                    RBTreeSetBlack(sibling->left);
                    RBTreeRightRotate(root, sibling);
                    sibling = parent->right;
                }
                /* node的兄弟结点sibling是黑色结点, sibling的左孩子是任意颜色, 右孩子是红色 */
                RBTreeSetColor(sibling, RBTreeColor(parent));
                RBTreeSetBlack(parent);
                RBTreeSetBlack(sibling->right);
                RBTreeLeftRotate(root, parent);
                node = root->node;
                break;
            }
        } else {
            sibling = parent->left;
            /* node的兄弟结点sibling是红色结点 */
            if (RBTreeIsRed(sibling)) {
                RBTreeSetBlack(sibling);
                RBTreeSetRed(parent);
                RBTreeRightRotate(root, parent);
                sibling = parent->left;
            }
            /* node的兄弟结点sibling是黑色结点, sibling的2个孩子结点都是黑色结点 */
            if ((!sibling->left || RBTreeIsBlack(sibling->left)) &&
                (!sibling->right || RBTreeIsBlack(sibling->right))) {
                RBTreeSetRed(sibling);
                node = parent;
                parent = RBTreeParent(node);
            } else {
                /* node的兄弟结点sibling是黑色结点, sibling的左孩子是红色, 右孩子是黑色 */
                if (!sibling->left || RBTreeIsBlack(sibling->left)) {
                    RBTreeSetBlack(sibling->right);
                    RBTreeSetRed(sibling);
                    RBTreeLeftRotate(root, sibling);
                    sibling = parent->left;
                }
                /* node的兄弟结点sibling是黑色结点, sibling的左孩子是任意颜色, 右孩子是红色 */
                RBTreeSetColor(sibling, RBTreeColor(parent));
                RBTreeSetBlack(parent);
                RBTreeSetBlack(sibling->left);
                RBTreeRightRotate(root, parent);
                node = root->node;
                break;
            }
        }
    }
    if (node) RBTreeSetBlack(node);

    return SUCCESS;
}

/**
 * 红黑树删除结点指针
 *
 * @param[in]  root: the root of the red-black tree
 * @param[in]  node: the deleted node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status deleteRBTreeNode(RBRoot *root, Node *node)
{
    Node *child = NULL, *parent = NULL;
    int color;

    /* 删除结点的左右孩子结点都存在 */
    if (node->left && node->right) {
        Node *replace = node;
        /* 替代结点, 即后继结点 */
        replace = replace->right;
        /* 获取最小的后继结点 */
        while (replace->left) replace = replace->left;

        /* node结点不是根结点 */
        if (RBTreeParent(node)) {
            if (node == RBTreeParent(node)->left) RBTreeParent(node)->left = replace;
            else RBTreeParent(node)->right = replace;
        } else root->node = replace;  /* node结点是根结点 */

        /* child是替代结点的右孩子, 可能需要填补替代结点的位置 */
        child = replace->right;
        /* 保存替代结点的父结点 */
        parent = RBTreeParent(replace);
        /* 保存替代结点的颜色 */
        color = RBTreeColor(replace);

        /* 替代结点是删除结点的右孩子结点 */
        if (parent == node) parent = replace;
        else {
            if (child) RBTreeSetParent(child, parent);
            /* 替代结点的右孩子结点填补替代结点的位置(替代结点不可能有左孩子结点, 否则其才是后继结点) */
            parent->left = child;
            replace->right = node->right;
            RBTreeSetParent(node->right, replace);
        }

        /* 替代结点操作 */
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;
        node->left->parent = replace;

        /* 替代结点为黑色, 需要自平衡 */
        if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
        free(node);

        return SUCCESS;
    }

    /* 删除结点只存在一个孩子结点或者没有孩子结点 */
    if (node->left) child = node->left;
    else child = node->right;
    parent = node->parent;
    color = node->color;
    if (child) child->parent = parent;

    /* node结点不是根结点 */
    if (parent) {
        if (node == parent->left) parent->left = child;
        else parent->right = child;
    } else root->node = child;

    if (color == BLACK) RBTreeDeleteSelfBalancing(root, child, parent);
    free(node);

    return SUCCESS;
}

/**
 * 红黑树信息的打印
 *
 * @param[in]  tree    : the node of the red-black tree
 * @param[in]  data    : the data of the node
 * @param[in]  position: 0 - the current node is the root node
 *                      -1 - the current node is the left child node
 *                       1 - the current node is the right child node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position)
{
    if (tree) {
        if (position == 0) printf("[%d] (黑) 是根节点\n", tree->data);
        else printf("[%d] (%s) 是 [%d] 的 {%s} 孩子结点\n", tree->data, RBTreeIsRed(tree) ? "红" : "黑",
                    data, position == -1 ? "左" : "右");

        PrintRBTreeInfo(tree->left, tree->data, -1);
        PrintRBTreeInfo(tree->right, tree->data, 1);

        return SUCCESS;
    }

    return FAILED;
}

/**
 * 凹入法打印红黑树
 *
 * @param[in]  tree : the node of the red-black tree
 * @param[in]  depth: the depth of the red-black tree node
 * @return  the operation status, SUCCESS is 0, FAILED is -1
 */
Status recessedPrintRBTree(RBTree tree, int depth)
{
    if (!tree) return FAILED;
    recessedPrintRBTree(tree->right, depth + 1);
    for (int i = 0; i < depth; i++) printf("    ");
    printf("[%-d(%s)]\n", tree->data, RBTreeIsRed(tree) ? "红" : "黑");
    recessedPrintRBTree(tree->left, depth + 1);

    return SUCCESS;
}
