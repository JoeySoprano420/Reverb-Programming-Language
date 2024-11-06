class SimpleSyntaxParser : public Parser {
    std::unique_ptr<Node> parseGauge() override {
        auto gauge = std::make_unique<GaugeNode>();
        gauge->resource = "cpu";  // Example simplified parsing
        return gauge;
    }
};
