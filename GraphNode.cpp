//
// Created by Brandon Robinson on 4/12/24.
//
#include <iostream>
#include <cstdlib>
#include "GraphNode.hpp"

GraphNode::GraphNode( std::string name ) {
    _name = name;
    _command = "";
    _timestamp = 0;
    _listOfDependentNodes = new std::vector<GraphNode*>;
    _onPath = false;
    _isATarget = false;
    _wasMade = false;
}

std::string GraphNode::getName() {
    return _name;
}

void GraphNode::setName(std::string name) {
    _name = name;
}

void GraphNode::setTimestamp(int ts) {
    _timestamp = ts;
}

int GraphNode::getTimestamp() {
    return _timestamp;
}

void GraphNode::setCommand(std::string cmnd) {
    _command = cmnd;
}

std::string GraphNode::getCommand() {
    return _command;
}

std::vector<GraphNode *> *GraphNode::dependentNodes() {
    return _listOfDependentNodes;
}

void GraphNode::addDependentNode(GraphNode *child) {
    _listOfDependentNodes->push_back(child);
}

bool GraphNode::onPath() {
    return _onPath;
}

void GraphNode::onPath(bool v) {
    _onPath = v;
}

bool GraphNode::wasMade() {
    return _wasMade;
}

void GraphNode::wasMade(bool v) {
    _wasMade = v;
}

bool GraphNode::isATarget() {
    return _isATarget;
}

void GraphNode::isATarget(bool v) {
    _isATarget = v;
}

int GraphNode::numDependentNodes() {
    return _listOfDependentNodes->size();
}

void GraphNode::print() {
    if (isATarget()) {
        std::cout << _name << ": ";
        for (size_t i = 0; i < numDependentNodes(); ++i) {
            std::cout << _listOfDependentNodes->at(i)->_name << " ";
        }
        std::cout << std::endl << "\t" << _command << std::endl;
    }
}
