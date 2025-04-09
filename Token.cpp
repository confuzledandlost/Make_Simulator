
#include <iostream>
#include "Token.hpp"

Token::Token():                   _isColon{false},
                                 _isCommand{false},
                                 _isNewLine{false},
                                 _isTab{false},
                                 _tokenName{""},
                                 _isDependency{false},
                                 _isTarget{false},
                                 _eof{false} {}

bool &Token::isColon() { return _isColon; }

bool &Token::isCommand() { return _isCommand; }

bool &Token::isNewLine() { return _isNewLine; }

bool &Token::endOfFile() { return _eof; }

bool &Token::isTarget() { return _isTarget; }

bool &Token::isDependency() { return _isDependency; }

bool &Token::isTab() { return _isTab; }

std::string &Token::tokenName() { return _tokenName; }

void Token::print() {

    std::cout << this->tokenName() << std::endl;

}

void Token::makeColon() {

    this->isColon() = true;
    this->tokenName() = ":";

}

void Token::makeNewLIne() {

    this->isNewLine() = true;
    this->tokenName() = "\n";

}

void Token::makeCommand(std::string name) {

    this->isCommand() = true;
    this->tokenName() = name;

}

void Token::makeTab() {

    this->isTab() = true;
    this->tokenName() = "\t";

}

void Token::makeEndofFile() {

    this->endOfFile() = true;
    this->tokenName() = EOF;

}

void Token::makeTarget(std::string name) {

    this->isTarget() = true;
    this->tokenName() = name;

}
void Token::makeDepenency(std::string name) {

    this->isDependency() = true;
    this->tokenName() = name;

}
