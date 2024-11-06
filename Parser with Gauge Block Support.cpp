#include <memory>

struct Node {
    virtual ~Node() = default;
};

struct GaugeNode : Node {
    std::string resource;
    int base;
    bool adaptive;
};

class Parser {
public:
    explicit Parser(const std::vector<Token> &tokens) : tokens(tokens), position(0) {}

    std::unique_ptr<Node> parse() {
        if (match(GAUGE)) return parseGauge();
        return nullptr;
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

    std::unique_ptr<GaugeNode> parseGauge() {
        auto gauge = std::make_unique<GaugeNode>();
        // Parse details specific to the gauge block here
        return gauge;
    }
};
