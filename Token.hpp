
#ifndef _TOKEN_HPP
#define _TOKEN_HPP

#include <string>

class Token {
public:
    Token();
    bool& isColon();
    bool& isNewLine();
    bool& isCommand();
    bool& isTab();
    bool& endOfFile();
    bool& isTarget();
    bool& isDependency();

    void makeColon();
    void makeNewLIne();
    void makeCommand(std::string);
    void makeTab();
    void makeEndofFile();
    void makeTarget(std::string);
    void makeDepenency(std::string);

    void print();

    std::string& tokenName();

private:
    bool _isColon = false, _isNewLine = false, _isTarget = false, _isDependency = false,
            _eof = false, _isCommand = false, _isTab = false;

    std::string _tokenName;
    // int _lineNumber, _charPos;
};

#endif