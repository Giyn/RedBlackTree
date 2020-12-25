/**
 * @filename rbtree.c
 * @description RBTree interface implementation
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

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
 * 销毁红黑树
 *
 * @param[in]  tree  the node of the red-black tree
 * @return  none
 */
static void rbtree_destroy(RBTree tree) {
    if (!tree) return;

    if (tree->left) rbtree_destroy(tree->left);
    if (tree->right) rbtree_destroy(tree->right);

    free(tree);
}
