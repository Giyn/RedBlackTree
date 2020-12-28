cmake_minimum_required(VERSION 3.17)
project(RBTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RBTree main.c RBTree.c RBTree.h RBTreeUtils.h RBTreeUtils.c BinaryTree.c BinaryTree.h BinarySearchTree.c BinarySearchTree.h)