cmake_minimum_required(VERSION 3.27)
project(cs315project4)

set(CMAKE_CXX_STANDARD 17)

add_executable(cs315project4 main.cpp
        Token.hpp
        Token.cpp
        Tokenizer.hpp
        Tokenizer.cpp
        GraphNode.hpp
        GraphNode.cpp
        MakeTree.cpp
        TreeNode.cpp
        DepGraph.cpp
        systemInterface.cpp)
