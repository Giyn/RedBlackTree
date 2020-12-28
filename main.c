/**
 * @filename main.c
 * @description Red-Black Tree test
 * @author 许继元
 * @date 2020/12/18
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "RedBlackTree.h"

_Noreturn void menu();

int InputInteger();

void main() {
    RBRoot *root = NULL;
    menu(root);
}

/**
 * 用户操作菜单
 *
 * @param[in]  root: the root of the red-black tree
 * @return  none
 */
_Noreturn void menu(RBRoot *root) {
    int exist_flag = 0;
    int delete_x;
    int insert_x;
    int search_x;
    while (true) {
        system("cls");
        printf("\n\n\n");
        printf("-------------------------------\n");
        printf(">>> 1.初始化红黑树\n");
        printf(">>> 2.打印红黑树\n");
        printf(">>> 3.销毁红黑树\n");
        printf(">>> 4.删除结点\n");
        printf(">>> 5.插入结点\n");
        printf(">>> 6.插入指定数量的随机(1-100)结点\n");
        printf(">>> 7.查找结点\n");
        printf(">>> 8.前序遍历\n");
        printf(">>> 9.中序遍历\n");
        printf(">>> 10.后序遍历\n");
        printf(">>> 11.退出\n");
        printf("-------------------------------\n");
        if(exist_flag) {
            inorderRBTree(root); /* 实时遍历红黑树 */
            printf("\n");
        }
        else printf("不存在红黑树!\n");
        printf("-------------------------------\n");
        printf("----->>> 请输入你想执行的操作:");

        switch (InputInteger()) {
            case 1:  /* 初始化 */
                root = createRBTree();
                exist_flag = 1;
                printf("初始化红黑树成功!\n");
                break;
            case 2:  /* 打印 */
                if (exist_flag) printRBTree(root);
                else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 3:  /* 销毁 */
                if (exist_flag) {
                    destroyRBTree(root);
                    exist_flag = 0;
                    printf("销毁红黑树成功!\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 4:  /* 删除 */
                if (exist_flag) {
                    printf("请输入你想删除的结点:");
                    delete_x = InputInteger();
                    if ((deleteRBTree(root, delete_x)) == OK) printf("删除结点成功!\n");
                    else printf("删除结点失败, 不存在该结点!\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 5:  /* 插入 */
                if (exist_flag){
                    printf("请输入你想插入的结点:");
                    insert_x = InputInteger();
                    insertRBTree(root, insert_x);
                    printf("插入结点成功!\n");
                }
                else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 6:  /* 随机插入指定数量的结点 */
                if (exist_flag) {
                    /* 设置随机数种子 */
                    srand((unsigned int) time(NULL));
                    printf("请输入你想插入的结点数量:");
                    int i, length_of_array;
                    length_of_array = InputInteger();
                    /* 以变量表示数组长度 */
                    int *const array = (int *) malloc(sizeof(int) * length_of_array);
                    /* 生成元素位于1~100的数组 */
                    for (i = 0; i < length_of_array; i++) array[i] = rand() % 100;
                    printf("插入的结点为: ");
                    for (i = 0; i < length_of_array; i++) {
                        printf("%d ", array[i]);
                        insertRBTree(root, array[i]);
                    }
                    printf("\n插入结点成功!\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 7:  /* 查找 */
                if (exist_flag) {
                    printf("请输入你想查找的结点:");
                    search_x = InputInteger();
                    if ((recursiveSearchRBTree(root, search_x)) == OK) printf("查找成功, 存在该结点!\n");
                    else printf("查找失败, 不存在该结点!\n");
                }
                break;
            case 8:  /* 前序遍历 */
                if (exist_flag) {
                    preorderRBTree(root);
                    printf("\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 9:  /* 中序遍历 */
                if (exist_flag) {
                    inorderRBTree(root);
                    printf("\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 10:  /* 后序遍历 */
                if (exist_flag) {
                    postorderRBTree(root);
                    printf("\n");
                } else printf("不存在红黑树, 请先初始化!\n");
                break;
            case 11:  /* 退出程序 */
                printf("再见!");
                exit(0);
            default:
                break;
        }
        system("pause");
    }
}

/**
 * 检测用户整数输入
 *
 * @param[in]  none
 * @return  legal integer
 */
int InputInteger() {
    /* store converted numbers */
    int integer = 0;
    /* flag status */
    Status status = FALSE;
    /* receive string */
    char str[100];

    do {
        scanf("%s", str);
        status = SUCCESS;
        int i;
        for (i = 0; str[i] != '\0'; i++) {
            /* check for illegal characters */
            if (i == 0) {
                if (str[i] == '-' || str[i] == '+') continue;
            } else {
                if (str[i] < '0' || str[i] > '9') status = FALSE;
            }
        }
        if (status == FALSE) {
            printf("输入非法, 请重新输入!\n");
            break;
        } else {
            /* Convert string to number */
            for (i = 0, integer = 0; str[i] != '\0'; i++) {
                if (i == 0) {
                    if (str[i] == '-' || str[i] == '+') continue;
                    else {
                        integer *= 10;
                        integer += (str[i] - 48);
                    }
                } else {
                    integer *= 10;
                    integer += (str[i] - 48);
                }
            }
            if (str[0] == '-') integer = -integer;

            /* check if the number entered is out of bounds */
            if (i >= 10) {
                printf("溢出, 请重新输入:");
                status = FALSE;
            }
        }
    } while (status == FALSE);

    return integer;
}
