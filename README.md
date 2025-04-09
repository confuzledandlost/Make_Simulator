# Make Utility Project

This project implements a simplified version of the `make` utility that processes a custom makefile format to manage dependencies and execute commands. It validates dependency graphs, ensures correct build execution order, and handles circular dependency checks.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Dependencies](#dependencies)
- [Build Instructions](#build-instructions)
- [Usage](#usage)
- [Technical Details](#technical-details)
- [Known Issues](#known-issues)
- [Future Improvements](#future-improvements)

---

## Overview

The project is designed to mimic the behavior of the `make` program by:
- Parsing a simplified makefile to construct a dependency graph.
- Handling targets, their dependencies, and associated commands.
- Validating timestamps to determine whether a target needs to be rebuilt.
- Managing cyclic dependencies to avoid infinite loops.
- Executing shell commands associated with targets.

The makefile format is as follows:
1. A target line begins with a target and its dependencies, separated by a colon (`:`).
2. Commands associated with the target are indented with a tab (`\t`).
3. Targets, dependencies, and commands are processed sequentially.

---

## Features

- **Target-Dependency Hierarchy:** Builds a binary search tree (BST) for managing nodes and dependencies.
- **Timestamp Management:** Compares timestamps of targets and dependencies to decide if rebuilding is required.
- **Cyclic Dependency Detection:** Checks for cycles in the dependency graph.
- **Command Execution:** Executes shell commands defined in the makefile.
- **In-order Traversal Display:** Allows in-order traversal and display of the target-dependency tree.

---

## Dependencies

This project requires:
- **C++17 or higher**
- Standard C++ libraries (`<iostream>`, `<string>`, `<fstream>`, etc.)
- A UNIX-based system for shell command execution
- A compatible compiler (e.g., `g++`)

---

## Directory Structure

src/
|-- main.cpp                 # The entry point of the program
|-- GraphNode.hpp/.cpp       # Represents nodes of the dependency graph
|-- TreeNode.hpp/.cpp        # Represents tree nodes in the binary search tree
|-- MakeTree.hpp/.cpp        # Manages the binary search tree
|-- DepGraph.hpp/.cpp        # Manages the dependency graph and its operations
|-- Token.hpp/.cpp           # Handles representations of tokens from the makefile
|-- Tokenizer.hpp/.cpp       # Parses tokens from the makefile
|-- systemInterface.hpp/.cpp # Provides utility functions for file and command operations
Makefile                     # Build instructions for the project
README.md                    # Documentation for the project

---

## Build Instructions

### Using the Provided Makefile

1. Clone this repository:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```

2. To build the project, run:
    ```bash
    make
    ```
   This will generate the `make.x` executable.

3. To clean up build files:
    ```bash
    make clean
    ```

---

## Usage

Run the program with the name of a makefile as the argument:

```bash
./make.x <makefile>
```

### Example:

Let's assume you have a makefile named `example.mk` with the following content:

```makefile
target1: dependency1 dependency2
    echo Compiling target1

dependency1:
    echo Building dependency1

dependency2:
    echo Building dependency2
```

Execute the program:

```bash
./make.x example.mk
```

---

## Technical Details

### Components

1. **Tokenizer**: Reads the makefile line by line and extracts meaningful tokens, such as targets, dependencies, and commands.
   - Handles improperly formatted makefiles and raises errors where necessary.

2. **Dependency Graph**: Represents targets as nodes and their dependencies as edges. Implemented using the `GraphNode` class, it ensures efficient management of dependencies.

3. **Binary Search Tree**: The `MakeTree` class uses a BST to manage all graph nodes for quick retrieval and insertion.

4. **System Interface**: A set of helper functions that:
   - Check whether a file exists (`fileExists()`).
   - Retrieve the last modification timestamp of a file (`timestampForFile()`).
   - Execute shell commands (`executeCommand()`).

5. **Circular Dependency Check**: Uses recursive backtracking to detect cycles in the dependency graph before processing targets.

### Key Workflow

1. **Parsing the Makefile:** 
   - Starts with the first target and reads dependencies, constructing the graph.
   - Maps targets to shell commands if they exist.

2. **Graph Traversal:** 
   - Performs a depth-first traversal to process targets in the correct build order.
   - Compares timestamps and executes commands only for outdated targets.

3. **Cycle Detection:** 
   - Implemented as a recursive function that halts processing when a cycle is encountered.

---

## Known Issues

- The current implementation assumes that the makefile is well-structured. Error handling for deeply malformed makefiles might be limited.
- May not handle complex shell command strings with special characters perfectly.
- Only supports the UNIX platform for command execution due to reliance on `system()`.

---

## Future Improvements

- **Cross-platform Support:** Replace `system()` with a more robust mechanism for command execution.
- **Parallel Execution:** Support parallel processing for independent targets.
- **Enhanced Syntax:** Extend the parser to support comments and more advanced makefile syntax.
- **Improved Error Messages:** Provide detailed error messages for malformed makefiles.
- **Memory Management:** Improve memory handling across dynamically allocated structures.

---

## Author

Brandon Robinson (Created the project functionality on **4/12/24**).

---

## License

This project is distributed for educational purposes. Refer to the LICENSE file (if included) for more details.