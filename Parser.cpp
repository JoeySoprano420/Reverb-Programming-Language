#include <memory>

struct Node {
    virtual ~Node() = default;
};

struct GaugeNode : Node {
    int base;
    int stretch;
    bool adaptive;
};

class Parser {
public:
    explicit Parser(const std::vector<Token> &tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<Node> parse
#include <memory>
#include <vector>
#include <stdexcept>

struct Node {
    virtual ~Node() = default;
};

struct GaugeNode : Node {
    int base;
    int stretch;
    bool adaptive;
};

class Parser {
public:
    explicit Parser(const std::vector<Token> &tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<Node> parse() {
        if (match(GAUGE)) {
            return parseGauge();
        }
        throw std::runtime_error("Expected 'gauge' statement.");
    }

private:
    std::vector<Token> tokens;
    size_t position;

    bool match(TokenType type) {
        if (tokens[position].type == type) {
            position++;
            return true;
        }
        return false;
    }

    Token consume(TokenType type, const std::string &errorMessage) {
        if (tokens[position].type == type) {
            return tokens[position++];
        }
        throw std::runtime_error(errorMessage);
    }

    std::unique_ptr<GaugeNode> parseGauge() {
        auto gaugeNode = std::make_unique<GaugeNode>();

        consume(BRACE_OPEN, "Expected '{' after 'gauge' keyword.");

        while (tokens[position].type != BRACE_CLOSE && tokens[position].type != END_OF_FILE) {
            if (match(BASE)) {
                consume(COLON, "Expected ':' after 'base'");
                gaugeNode->base = parsePercentage();
            } else if (match(STRETCH)) {
                consume(COLON, "Expected ':' after 'stretch'");
                gaugeNode->stretch = parsePercentage();
            } else if (match(ADAPTIVE)) {
                gaugeNode->adaptive = true;
            } else {
                throw std::runtime_error("Unexpected token inside 'gauge' block.");
            }
        }

        consume(BRACE_CLOSE, "Expected '}' at the end of 'gauge' block.");
        return gaugeNode;
    }

    int parsePercentage() {
        Token token = consume(NUMBER, "Expected percentage value.");
        int value = std::stoi(token.value);
        consume(PERCENTAGE, "Expected '%' after percentage value.");
        return value;
    }
};
struct PulseNode : Node {
    int frequency;
    bool stabilize;
};

struct AutoAdjustNode : Node {};

struct ProgramNode : Node {
    std::vector<std::unique_ptr<Node>> statements;
};
class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<ProgramNode> parseProgram() {
        auto programNode = std::make_unique<ProgramNode>();

        while (position < tokens.size() && tokens[position].type != END_OF_FILE) {
            if (match(GAUGE)) {
                programNode->statements.push_back(parseGauge());
            } else if (match(PULSE)) {
                programNode->statements.push_back(parsePulse());
            } else if (match(AUTO_ADJUST)) {
                programNode->statements.push_back(parseAutoAdjust());
            } else {
                throw std::runtime_error("Unexpected token at program level.");
            }
        }
        return programNode;
    }

private:
    std::vector<Token> tokens;
    size_t position;

    bool match(TokenType type) {
        if (tokens[position].type == type) {
            position++;
            return true;
        }
        return false;
    }

    Token consume(TokenType type, const std::string& errorMessage) {
        if (tokens[position].type == type) {
            return tokens[position++];
        }
        throw std::runtime_error(errorMessage);
    }

    std::unique_ptr<GaugeNode> parseGauge() {
        auto gaugeNode = std::make_unique<GaugeNode>();
        consume(BRACE_OPEN, "Expected '{' after 'gauge' keyword.");

        while (tokens[position].type != BRACE_CLOSE && tokens[position].type != END_OF_FILE) {
            if (match(BASE)) {
                consume(COLON, "Expected ':' after 'base'");
                gaugeNode->base = parsePercentage();
            } else if (match(STRETCH)) {
                consume(COLON, "Expected ':' after 'stretch'");
                gaugeNode->stretch = parsePercentage();
            } else if (match(ADAPTIVE)) {
                gaugeNode->adaptive = true;
            } else {
                throw std::runtime_error("Unexpected token inside 'gauge' block.");
            }
        }
        consume(BRACE_CLOSE, "Expected '}' at the end of 'gauge' block.");
        return gaugeNode;
    }

    std::unique_ptr<PulseNode> parsePulse() {
        auto pulseNode = std::make_unique<PulseNode>();

        consume(BRACE_OPEN, "Expected '{' after 'pulse' keyword.");

        while (tokens[position].type != BRACE_CLOSE && tokens[position].type != END_OF_FILE) {
            if (match(FREQUENCY)) {
                consume(COLON, "Expected ':' after 'frequency'");
                pulseNode->frequency = parseNumber();
            } else if (match(STABILIZE)) {
                pulseNode->stabilize = true;
            } else {
                throw std::runtime_error("Unexpected token inside 'pulse' block.");
            }
        }

        consume(BRACE_CLOSE, "Expected '}' at the end of 'pulse' block.");
        return pulseNode;
    }

    std::unique_ptr<AutoAdjustNode> parseAutoAdjust() {
        return std::make_unique<AutoAdjustNode>();
    }

    int parsePercentage() {
        Token token = consume(NUMBER, "Expected percentage value.");
        int value = std::stoi(token.value);
        consume(PERCENTAGE, "Expected '%' after percentage value.");
        return value;
    }

    int parseNumber() {
        Token token = consume(NUMBER, "Expected integer value.");
        return std::stoi(token.value);
    }
};
class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<Node> parse() {
        // Parse logic goes here
        return parseProgram();
    }

private:
    std::vector<Token> tokens;
    size_t position;

    std::unique_ptr<Node> parseProgram() {
        // Parse program logic
    }

    std::unique_ptr<Node> parseFunction() {
        // Parse function logic
    }

    std::unique_ptr<Node> parseGauge() {
        // Parse gauge logic
    }
    
    std::unique_ptr<Node> parseConditional() {
        // Parse conditional logic
    }

    std::unique_ptr<Node> parseLoop() {
        // Parse loop logic
    }
};

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<Node> parse() {
        // Parse logic goes here
        return parseProgram();
    }

private:
    std::vector<Token> tokens;
    size_t position;

    std::unique_ptr<Node> parseProgram() {
        // Logic to parse the entire program
    }

    std::unique_ptr<Node> parseFunction() {
        // Logic to parse function definitions
    }

    std::unique_ptr<Node> parseGauge() {
        // Logic to parse gauge definitions
    }

    std::unique_ptr<Node> parseConditional() {
        // Logic to parse conditional statements
    }

    std::unique_ptr<Node> parseLoop() {
        // Logic to parse loops
    }

    std::unique_ptr<Node> parseErrorHandling() {
        // Logic to parse error handling
    }
};
