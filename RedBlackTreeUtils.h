/**
 * @filename RedBlackTreeUtils.h
 * @description Red-Black tree utils interface declaration
 * @author 许继元
 * @date 2020/12/18
 */

#ifndef RBTREEUTILS_H
#define RBTREEUTILS_H

/* 创建红黑树结点 */
RBTree createRBTreeNode(RBTreeElemType x, Node *parent, Node *left, Node *right);

/* 红黑树插入结点后自平衡 */
Status RBTreeInsertSelfBalancing(RBRoot *root, Node *node);

/* 红黑树查找最小结点 */
Status minRBTreeNode(RBRoot *root, RBTreeElemType *minVal);

/* 红黑树查找最大结点 */
Status maxRBTreeNode(RBRoot *root, RBTreeElemType *maxVal);

/* 红黑树删除结点后自平衡 */
Status RBTreeDeleteSelfBalancing(RBRoot *root, Node *node, Node *parent);

/* 红黑树删除结点指针 */
Status deleteRBTreeNode(RBRoot *root, Node *node);

/* 红黑树信息的打印 */
Status PrintRBTreeInfo(RBTree tree, RBTreeElemType data, int position);

/* 凹入法打印红黑树 */
Status recessedPrintRBTree(RBTree tree, int depth);

#endif /* RBTREEUTILS_H */
