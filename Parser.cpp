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
