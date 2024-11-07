struct Node {
    virtual ~Node() = default;
};

struct FunctionNode : Node {
    std::string name;
    std::vector<std::unique_ptr<Node>> parameters;
    std::unique_ptr<Node> body;
};

struct GaugeNode : Node {
    std::string name;
    float base;
    float stretch;
    bool adaptive;
};

struct ConditionalNode : Node {
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> thenBlock;
    std::unique_ptr<Node> elseBlock;
};

struct LoopNode : Node {
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> body;
};

struct Node {
    virtual ~Node() = default;
};

struct FunctionNode : Node {
    std::string name;
    std::vector<std::unique_ptr<Node>> parameters;
    std::unique_ptr<Node> body;
};

struct GaugeNode : Node {
    std::string name;
    float base;
    float stretch;
    bool adaptive;
};

struct ConditionalNode : Node {
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> thenBlock;
    std::unique_ptr<Node> elseBlock;
};

struct LoopNode : Node {
    std::unique_ptr<Node> condition;
    std::unique_ptr<Node> body;
};

struct ErrorNode : Node {
    std::string message;
};
