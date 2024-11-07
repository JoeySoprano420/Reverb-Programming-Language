class ReverbREPL {
public:
    ReverbREPL() : runtime(std::make_unique<ReverbRuntime>()) {}

    void start() {
        std::string input;
        std::cout << "Welcome to Reverb REPL! Type 'exit' to quit." << std::endl;

        while (true) {
            std::cout << "Reverb> ";
            std::getline(std::cin, input);

            if (input == "exit") {
                break;
            }

            try {
                auto tokens = tokenize(input);
                auto program = parser.parseProgram(tokens);
                executeProgram(*program);
            } catch (const std::exception& e) {
                runtime->reportError(e.what());
            }
        }
    }

private:
    std::unique_ptr<ReverbRuntime> runtime;
    Parser parser; // Assume the parser is already defined

    // Tokenization function (simple implementation for demonstration)
    std::vector<Token> tokenize(const std::string& input) {
        std::vector<Token> tokens;
        // Tokenize input string into Token objects
        // Fill tokens with appropriate values based on the input
        return tokens;
    }

    void executeProgram(const ProgramNode& program) {
        for (const auto& statement : program.statements) {
            if (auto gaugeNode = dynamic_cast<GaugeNode*>(statement.get())) {
                runtime->executeGauge(gaugeNode->base, gaugeNode->stretch);
            } else if (auto pulseNode = dynamic_cast<PulseNode*>(statement.get())) {
                runtime->executePulse(pulseNode->frequency, pulseNode->stabilize);
            } else if (dynamic_cast<AutoAdjustNode*>(statement.get())) {
                runtime->executeAutoAdjust();
            } else {
                runtime->executeCustomCommand("Unknown statement.");
            }
        }
    }
};
class ReverbREPL {
public:
    ReverbREPL() : runtime(std::make_unique<ReverbRuntime>()), library(std::make_unique<ReverbStandardLibrary>()) {}

    void start() {
        std::string input;
        std::cout << "Welcome to Reverb REPL! Type 'exit' to quit or 'help' for commands." << std::endl;

        while (true) {
            std::cout << "Reverb> ";
            std::getline(std::cin, input);

            if (input == "exit") {
                break;
            }

            if (input == "help") {
                displayHelp();
                continue;
            }

            try {
                auto tokens = tokenize(input);
                auto program = parser.parseProgram(tokens);
                executeProgram(*program);
            } catch (const std::exception& e) {
                runtime->reportError(e.what());
            }
        }
    }

private:
    std::unique_ptr<ReverbRuntime> runtime;
    std::unique_ptr<ReverbStandardLibrary> library; 
    Parser parser; // Assume the parser is already defined

    // Tokenization function (simple implementation for demonstration)
    std::vector<Token> tokenize(const std::string& input) {
        std::vector<Token> tokens;
        // Tokenize input string into Token objects
        // Fill tokens with appropriate values based on the input
        return tokens;
    }

    void executeProgram(const ProgramNode& program) {
        for (const auto& statement : program.statements) {
            if (auto gaugeNode = dynamic_cast<GaugeNode*>(statement.get())) {
                runtime->executeGauge(gaugeNode->base, gaugeNode->stretch);
            } else if (auto pulseNode = dynamic_cast<PulseNode*>(statement.get())) {
                runtime->executePulse(pulseNode->frequency, pulseNode->stabilize);
            } else if (dynamic_cast<AutoAdjustNode*>(statement.get())) {
                runtime->executeAutoAdjust();
            } else {
                runtime->executeCustomCommand("Unknown statement.");
            }
        }
    }

    void displayHelp() {
        std::cout << "Available commands:\n";
        std::cout << " - gauge <base> <stretch>: Set the gauge with base and stretch values.\n";
        std::cout << " - pulse <frequency> <stabilize>: Control the pulse frequency.\n";
        std::cout << " - autoAdjust: Automatically adjust system resources.\n";
        std::cout << " - status: Display current resource status.\n";
        std::cout << " - exit: Exit the REPL.\n";
        std::cout << " - help: Show this help message.\n";
    }
};
