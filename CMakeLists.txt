cmake_minimum_required(VERSION 3.17)
project(Huffmann)

set(CMAKE_CXX_STANDARD 20)

add_executable(Huffmann main.cpp H_Tree.cpp H_Tree.h H_Tree_Node.cpp H_Tree_Node.h H_Compression.cpp H_Compression.h)