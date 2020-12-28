cmake_minimum_required(VERSION 3.17)
project(RBTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RBTree main.c RedBlackTree.c RedBlackTree.h RedBlackTreeUtils.h RedBlackTreeUtils.c BinaryTree.c BinaryTree.h BinarySearchTree.c BinarySearchTree.h)