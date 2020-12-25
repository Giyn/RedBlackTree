/**
 * @filename RBTree.h
 * @description Red-Black Tree interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#ifndef RBTREE_H
#define RBTREE_H

#define RED   0 /* 红色结点标志 */
#define BLACK 1 /* 黑色结点标志 */

typedef int RBTreeElemType;

/* 红黑树的结点 */
typedef struct RBTreeNode {
    RBTreeElemType data;       /* 数据域 */
    char color;                /* 颜色 */
    struct RBTreeNode *left;   /* 左孩子结点 */
    struct RBTreeNode *right;  /* 右孩子结点 */
    struct RBTreeNode *parent; /* 父结点 */
} Node, *RBTree;

/* 红黑树的根结点 */
typedef struct RB_Root {
    Node *node;
} RBRoot;

/* 操作状态码 */
typedef enum {
    OK = 0,
    ERROR = -1
} Status;

/* 创建红黑树 */
RBRoot *createRBTree();

/* 销毁红黑树 */
Status destroyRBTree(RBRoot *root);

/* 前序遍历红黑树 */
Status preorderRBTree(RBRoot *root);

/* 中序遍历红黑树 */
Status inorderRBTree(RBRoot *root);

/* 后序遍历红黑树 */
Status postorderRBTree(RBRoot *root);

/* 递归查找红黑树 */
Status searchRBTree(RBRoot *root, RBTreeElemType x);

/* 插入结点到红黑树 */
Status insertRBTree(RBRoot *root, RBTreeElemType key);

#endif /* RBTREE_H */