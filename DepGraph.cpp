//
// Created by Brandon Robinson on 4/12/24.
//

#include "DepGraph.hpp"
#include <iostream>

DepGraph::DepGraph( std::string name ) {

    _fileToMake = name;
    _tree = new MakeTree;
    firstTarget = nullptr;

}

void DepGraph::print(GraphNode* currNode) {

    // Check if we're at a nullptr
    if (currNode == nullptr) return;

    // Print the node
    currNode->print();

    // Print the children of the current node
    for (int i = 0; i < currNode->numDependentNodes(); i++) {
        print(currNode->dependentNodes()->at(i));
    }

}

void DepGraph::parseDepGraph() {

    // Create our tokenizer
    Tokenizer tokenizer(_fileToMake);

    // Grab our first token
    Token token = tokenizer.getToken();

    // Build BST and Graph
    while (!token.endOfFile()) {

        // Figure out what the token is
        // If it's a target
        if (token.isTarget()) {

            // Figure out if a graph node for this doesn't exist
            if (_tree->find(token.tokenName()) == nullptr) {

                // If it doesn't exist, make a new node and assign token name to node name
                GraphNode* newGraphNode = new GraphNode(token.tokenName());

                // Check if file ACTUALLY exists in file system
                if (fileExists(newGraphNode->getName())) {

                    // Update the timestamp
                    newGraphNode->setTimestamp(timestampForFile(newGraphNode->getName()));

                }

                // If firstarget is nullptr then change to this value
                if (firstTarget == nullptr) firstTarget = newGraphNode;

                // Insert it into the graph... On second thought, I don't think this is a thing

                // Insert pointer to graphNode into bst
                _tree->insert(newGraphNode);

            }
            // Either way, grab the location
            GraphNode* currentGraphNode = _tree->find(token.tokenName());

            // Set the graph node as a target
            currentGraphNode->isATarget(true);

            // Grab new token
            token = tokenizer.getToken();

            // If it's a dependency
            while (token.isDependency()) {

                // Check if it's already in our graph
                if (_tree->find(token.tokenName()) == nullptr) {

                    // If it's not, then make graphNode with current token
                    GraphNode* dependentGraphNode = new GraphNode(token.tokenName());

                    // Check if file ACTUALLY exists in file system
                    if (fileExists(dependentGraphNode->getName())) {

                        // Update the timestamp
                        dependentGraphNode->setTimestamp(timestampForFile(dependentGraphNode->getName()));

                    }

                    // Insert pointer to graphnode into bst
                    _tree->insert(dependentGraphNode);

                }

                // Either way, insert it into the dependency vector
                currentGraphNode->addDependentNode(_tree->find(token.tokenName()));

                // Grab a new token before going to the top of the while loop
                token = tokenizer.getToken();

            }

            // If it's a command, assign the command to the current node
            if (token.isCommand()) {
                currentGraphNode->setCommand(token.tokenName());
            }
        }

        // Grab next token before next while loop
        token = tokenizer.getToken();

    }

    // Call Print function
    //_tree->print();

}

bool DepGraph::isCyclic(GraphNode* nNode) {

    // Check if the node is null and return false
    if (nNode == nullptr) return false;

    // Check if the node is on the path
    if (nNode->onPath()) return true;

    // Set node onPath to true
    nNode->onPath(true);

    // Loop that checks each dependency for cycles, recursively
    for (int i = 0; i < nNode->numDependentNodes(); i++) {

        if (isCyclic(nNode->dependentNodes()->at(i))) return true;

    }

    // Set node onPath to false
    nNode->onPath(false);

    return false;
}

void DepGraph::runMake() {

    // Call helper function and pass in depgraph root
    runMake(this->firstTarget);

    // If first target was made, output message
    if (!this->firstTarget->wasMade()) {
        std::cout << "make: '"<< this->firstTarget->getName() << "' is up to date.\n";
    }

}

void DepGraph::runMake(GraphNode* fileToMake) {

    // Back out if the file has already been made
    if (fileToMake->wasMade()) return;

    // Create a flag for if we find a dependency that is newer
    bool newerDependency = false;

    // Loop to recursively call runMake on dependencies
    for (int i = 0; i < fileToMake->numDependentNodes(); i++) {

        // Check if the dependency is a target
        if (fileToMake->dependentNodes()->at(i)->isATarget()) {

            // Recursively call runMake
            runMake(fileToMake->dependentNodes()->at(i));
        }
        // Check if file doesn't exist
        else if (!fileExists(fileToMake->dependentNodes()->at(i)->getName())) {
            std::cerr << "Dependency does not exist\n";
            exit(5);
        }
        // If the dependency was made set newerDependency flag to true
        if (fileToMake->dependentNodes()->at(i)->wasMade()) newerDependency = true;
        // Check if timestamp of dependency is newer
        else if (fileToMake->dependentNodes()->at(i)->getTimestamp() > fileToMake->getTimestamp()) {
            newerDependency = true;
        }

    }
    // Check if newer dependencies were updated after loop
    if(newerDependency == true) {

        // Run system interface command for executing the graph node command on the file
        executeCommand(fileToMake->getCommand());

        // Set was made to true
        fileToMake->wasMade(true);
    }

}

