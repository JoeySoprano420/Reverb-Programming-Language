int main() {
    std::string code = "gauge cpuUsage(base: 70%, stretch: 10%) { autoAdjust(); }";
    Lexer lexer(code);
    auto tokens = lexer.tokenize();

    for (const auto &token : tokens) {
        std::cout << "Token: " << token.value << std::endl;
    }
    return 0;
}
