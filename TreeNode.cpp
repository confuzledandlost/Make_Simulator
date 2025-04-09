//
// Created by Brandon Robinson on 4/12/24.
//

#include "TreeNode.hpp"

TreeNode::TreeNode( GraphNode *nNode ) {
    makeNode = nNode;
    rightSubtree = nullptr;
    leftSubtree = nullptr;
}

TreeNode *TreeNode::left() {
    return leftSubtree;
}

void TreeNode::left(TreeNode *leftPtr) {
    leftSubtree = leftPtr;
}


TreeNode *TreeNode::right() {
    return rightSubtree;
}


void TreeNode::right(TreeNode *rightPtr) {
    rightSubtree = rightPtr;
}

void TreeNode::print() {
    this->graphNode()->print();
}

GraphNode *TreeNode::graphNode() {
    return makeNode;
}
