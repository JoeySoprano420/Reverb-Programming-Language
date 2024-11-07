class ReverbRuntime {
public:
    // Constructor, OpenCL setup, etc.

    void executeGauge(int base, int stretch) {
        try {
            std::cout << "[INFO] Executing Gauge with base: " << base << " and stretch: " << stretch << std::endl;
            // Gauge kernel execution code
        } catch (const std::exception &e) {
            std::cerr << "[ERROR] Gauge execution failed: " << e.what() << std::endl;
        }
    }

    void executePulse(int frequency, bool stabilize) {
        try {
            std::cout << "[INFO] Executing Pulse with frequency: " << frequency << " and stabilize: " << stabilize << std::endl;
            // Pulse kernel execution code
        } catch (const std::exception &e) {
            std::cerr << "[ERROR] Pulse execution failed: " << e.what() << std::endl;
        }
    }

    void logDiagnosticInfo() {
        std::cout << "[DIAGNOSTIC] CPU Usage: " << getCpuUsage() << "%" << std::endl;
        std::cout << "[DIAGNOSTIC] Memory Usage: " << getMemoryUsage() << "MB" << std::endl;
    }

    int getCpuUsage() {
        // Platform-specific CPU usage
        return 50; // Example percentage
    }

    int getMemoryUsage() {
        // Platform-specific memory usage
        return 1024; // Example in MB
    }

private:
    std::vector<cl::Platform> platforms;
    std::vector<cl::Device> devices;
    cl::Context context;
    cl::CommandQueue queue;
};
class ReverbException : public std::exception {
public:
    explicit ReverbException(const std::string& message) : msg(message) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

// Inside the ReverbRuntime methods, throw specific exceptions
void ReverbRuntime::executeGauge(int base, int stretch) {
    if (base < 0 || stretch < 0) {
        throw ReverbException("Base and stretch values must be non-negative.");
    }
    // Existing implementation...
}
