
#ifndef _TOKENIZER_HPP
#define _TOKENIZER_HPP

#include <string>
#include <fstream>
#include "Token.hpp"

class Tokenizer {

public:

    Tokenizer(std::string);
    Token getToken();

private:

    std::string inputFileName;
    std::ifstream inputStream;
};

#endif