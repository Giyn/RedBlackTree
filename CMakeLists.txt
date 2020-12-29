cmake_minimum_required(VERSION 3.17)
project(RedBlackTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlackTree main.c RedBlackTree.c HeaderFiles/RedBlackTree.h HeaderFiles/RedBlackTreeUtils.h RedBlackTreeUtils.c BinaryTree.c HeaderFiles/BinaryTree.h BinarySearchTree.c HeaderFiles/BinarySearchTree.h BalancedBinaryTree.c HeaderFiles/BalancedBinaryTree.h)