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
