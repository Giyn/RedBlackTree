cmake_minimum_required(VERSION 3.17)
project(RedBlackTree C)

set(CMAKE_C_STANDARD 99)

add_executable(RedBlackTree main.c SourceFiles/RedBlackTree.c HeaderFiles/RedBlackTree.h HeaderFiles/RedBlackTreeUtils.h SourceFiles/RedBlackTreeUtils.c SourceFiles/BinaryTree.c HeaderFiles/BinaryTree.h SourceFiles/BinarySearchTree.c HeaderFiles/BinarySearchTree.h SourceFiles/BalancedBinaryTree.c HeaderFiles/BalancedBinaryTree.h)