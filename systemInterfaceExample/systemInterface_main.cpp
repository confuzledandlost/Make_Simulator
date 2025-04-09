#include<iostream>
#include<string>

#include "systemInterface.hpp"

int main( int argc, char **argv ) {

  // This program demonstrates the use of the following 3 functions.
  // 1. fileExists(std::string fileName)
  // 2. timestampForFile(std::string fileName)
  // 3. executeCommand(std::string)

  // See systemInterface.cpp for the description of these functions.

  // The program requires an argument -- the name of a file
  // If the file exists, it prints its timestamp. Otherwise,
  // it prints a message indicating that the file doesn't exist.
  // Additionally, the program runs a pre-composed command
  // to demonstrate how you can pass a command to the underlying
  // shell to execute. 

    if( argc != 2 ) {
        std::cerr << argv[0] << ":: usage: " << argv[0] << " aFileName\n";
        return 1;
    }

    if( ! fileExists(argv[1])) {
      std::cout << "File " << argv[1] << " doesn't exist." << std::endl;
      return 0;
    }

    std::cout << "The timestamp of " << argv[1] << " is " << timestampForFile(argv[1]) << std::endl;


    // test executeCommand function.
    const std::string command = "g++ -std=c++20 -c systemInterface.cpp -o systemInterface.o";
    std::cout << "Output of executeCommand follows:\n";
    executeCommand(command);

    return 0;
}
