
#ifndef _Graph_hpp
#define _Graph_hpp

#include<iostream>
#include<cstring>
#include "MakeTree.hpp"
#include "Tokenizer.hpp"
#include "systemInterface.hpp"

class DepGraph {
public:
    DepGraph( std::string name );
    void print() { print(firstTarget);}
    void parseDepGraph();
    void runMake();
    bool isCyclic() {return isCyclic(firstTarget);}

private:
    bool isCyclic(GraphNode *);
    void print(GraphNode*);
    void runMake(GraphNode*);

private:
    std::string _fileToMake, _targetToMake;
    GraphNode *firstTarget;
    MakeTree *_tree;  // MakeTree implements a binary-search tree similar to BinSearchTree
};

#endif
