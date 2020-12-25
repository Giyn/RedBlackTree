/**
 * @filename rbtree.h
 * @description RBTree interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H

#define RED   0 /* 红色结点标志 */
#define BLACK 1 /* 黑色结点标志 */

typedef int Type;

/* 红黑树的结点 */
typedef struct RBTreeNode {
    Type key;                  /* 关键字 */
    unsigned char color;       /* 颜色 */
    struct RBTreeNode *left;   /* 左孩子 */
    struct RBTreeNode *right;  /* 右孩子 */
    struct RBTreeNode *parent; /* 父结点 */
} Node, *RBTree;

/* 红黑树的根结点 */
typedef struct rb_root {
    Node *node;
} RBRoot;

/* 创建红黑树 */
RBRoot *create_rbtree();

/* 销毁红黑树 */
void destroy_rbtree(RBRoot *root);

/* 前序遍历红黑树 */
void preorder_rbtree(RBRoot *root);

/* 中序遍历红黑树 */
void inorder_rbtree(RBRoot *root);

/* 后序遍历红黑树 */
void postorder_rbtree(RBRoot *root);

#endif /* RBTREE_RBTREE_H */
