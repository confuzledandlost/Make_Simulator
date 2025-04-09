
#include <iostream>
#include <cstdlib>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name):
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

Token Tokenizer::getToken() {
    // Char from input stream being analyzed
    char c;
    std::string tName = "";

    // Standard check to see if file is open
    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    // Checks for spaces
    while( inputStream.get(c) && c == ' ') {
        // Just keep going until we don't hit a space
    }

    // Once we hit a token...
    // Create a new token object
    Token token;

    // Check if it's the end of the file
    if( inputStream.eof() ) {
        token.makeEndofFile();
    }

    // Check for newline
    // In a well-structured makefile, if we have a new line, we should either run into...
    // 1. A target file name
    // 2. A tab, followed by a command
    // 3. An end of file
    // 4. A new line
    else if(c == '\n') {

        // If the first character is alpha or a number
        if (isalnum(inputStream.peek())) {

            // Get the whole target name
            inputStream >> tName;

            // Put the colon back if it was grabbed
            if (tName.at(tName.size() -1) == ':') {
                inputStream.unget();
                tName.pop_back();
            }

            // Make the target file token
            token.makeTarget(tName);
        }
        // Check if the next thing is a tab
        else if (inputStream.peek() == '\t') {
            inputStream.ignore();

            // Then check if the next thing after is a possible command
            if (isalpha(inputStream.peek())) {

                // Grab the rest of the command
                getline(inputStream, tName);

                // Make it a command token
                token.makeCommand(tName);
            }
        }
        // Check if the next thing is end of file
        else if( inputStream.peek() == EOF ) {
            token.makeEndofFile();
        }

        // Otherwise the makefile is improperly formatted
        else {
            std::cerr << "\nImproperly formatted make-file: \nNewline must be followed by a target, a tab, or EOF";
            exit (1);
        }
    }
    // Check for colon
    // In a well-structured makefile, if we have a colon, we should only run into...
    // 1. A dependency
    // 2. Whitespace until a dependency
    // 3. A new line
    else if (c == ':') {

        // Check if there's white space
        while (inputStream.get(c) && c == ' ') {
            // Keep going if there's white space
        }

        // If the first character is alpha or a number
        if (isalnum(inputStream.peek())) {

            // Throw the first character back in the stream
            inputStream.unget();

            // Get the whole dependency name
            inputStream >> tName;

            // Make the target file token
            token.makeDepenency(tName);
        }
        // Check if there's a newline
        else if (c == '\n') {
            // Put it back and let it keep going
            inputStream.unget();
            return getToken();
        }
        // Otherwise the makefile is improperly formatted
        else {
            std::cerr << "\nImproperly formatted make-file: \nColon must be followed by whitespace or a dependency file";
            exit (1);
        }
    }
    // If the first character is alpha or a number
    else if (isalnum(c)) {

        // Throw c back into the input stream
        inputStream.unget();

        // Get the whole dependency name
        inputStream >> tName;

        // Make the target file token
        token.makeDepenency(tName);
    }
        // Otherwise the makefile is improperly formatted
    else {
        std::cerr << "\nImproperly formatted make-file: \nNo tokens found.";
        exit (1);
    }

    return token;
}
