cmake_minimum_required(VERSION 3.17)
project(RedBlackTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlackTree main.c RedBlackTree.c RedBlackTree.h RedBlackTreeUtils.h RedBlackTreeUtils.c BinaryTree.c BinaryTree.h BinarySearchTree.c BinarySearchTree.h)