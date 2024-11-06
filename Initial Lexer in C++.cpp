#include <string>
#include <vector>
#include <regex>
#include <iostream>

enum TokenType {
    GAUGE, PULSE, AUTO_ADJUST, INCREASE_THRESHOLD, CPU_USAGE, MEMORY_USAGE, BASE, STRETCH,
    PERCENTAGE, BRACE_OPEN, BRACE_CLOSE, IDENTIFIER, EOF_TOKEN
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string &code) : code(code), position(0) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        while (position < code.size()) {
            if (match("gauge")) tokens.push_back({GAUGE, "gauge"});
            else if (match("pulse")) tokens.push_back({PULSE, "pulse"});
            else if (match("autoAdjust")) tokens.push_back({AUTO_ADJUST, "autoAdjust"});
            // Additional keywords and syntax handling...
            else position++; // Move forward if no match
        }
        tokens.push_back({EOF_TOKEN, ""});
        return tokens;
    }

private:
    std::string code;
    size_t position;

    bool match(const std::string &word) {
        if (code.substr(position, word.length()) == word) {
            position += word.length();
            return true;
        }
        return false;
    }
};
