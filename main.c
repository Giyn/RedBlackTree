/**
 * @filename main.c
 * @description Red-Black Tree test
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RedBlackTree.h"

void main() {
    int length_of_array, i;
    /* 设置随机数种子 */
    srand((unsigned int)time(NULL));

    printf("请输入一个正整数:");
    scanf("%d", &length_of_array);

    /* 以变量表示数组长度 */
    int* const array = (int*)malloc(sizeof(int)*length_of_array);
    /* 生成元素位于1~100的数组 */
    for (i = 0; i < length_of_array; i++) array[i] = rand() % 100;

    RBRoot *root = createRBTree();
    printf("生成的数组为: ");
    for (i = 0; i < length_of_array; i++) {
        printf("%d ", array[i]);
        insertRBTree(root, array[i]);
    }

    printf("\n前序遍历的结果: ");
    preorderRBTree(root);
    printf("\n中序遍历的结果: ");
    inorderRBTree(root);
    printf("\n后序遍历的结果: ");
    postorderRBTree(root);

    printf("\n删除结点: [%d], [%d].", array[length_of_array / 2], array[length_of_array / 3]);
    deleteRBTree(root, array[length_of_array / 2]);
    deleteRBTree(root, array[length_of_array / 3]);

    printf("\n前序遍历的结果: ");
    preorderRBTree(root);
    printf("\n中序遍历的结果: ");
    inorderRBTree(root);
    printf("\n后序遍历的结果: ");
    postorderRBTree(root);
}
