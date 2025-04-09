//
// Created by Brandon Robinson on 4/12/24.
//
#include "MakeTree.hpp"

MakeTree::MakeTree() {

    _root = nullptr;

};

TreeNode *MakeTree::insert(TreeNode *tNode, GraphNode *nNode) {

    // If we reach the end of the tree return a new node
    if (tNode == nullptr) return new TreeNode(nNode);

    // If the nNode value is less than the tNode value, traverse the right subtree
    if (nNode->getName() > tNode->graphNode()->getName()) tNode->right(insert(tNode->right(), nNode));

    // Otherwise traverse the left subtree
    else tNode->left(insert( tNode->left(), nNode));

    // If all else fails, return the root
    return tNode;

}

void MakeTree::print(TreeNode *root) {

    // If the root is null then back out
    if (root == nullptr) return;

    // Traverse left if there is a node to the let
    print(root->left());

    // If this is the farther left in our subtree, print the value
    root->graphNode()->print();

    // Now we go right, if we can
    print(root->right());

}

GraphNode *MakeTree::find(std::string name) {

    return find(_root, name);

}

GraphNode *MakeTree::find(TreeNode *root, std::string name) {

    // If we reach the end of the tree, return nullptr
    if (root == nullptr) return nullptr;

    // Return the graphnode if we find the value
    if (root->graphNode()->getName() == name) return root->graphNode();

    // If the root value is bigger, traverse the left subtree
    if (name < root->graphNode()->getName()) return find(root->left(), name);

    // Otherwise, traverse the right subtree
    return find(root->right(), name);

}
