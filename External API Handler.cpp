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
class APIHandler {
public:
    explicit APIHandler(const std::string& baseUrl) : baseUrl(baseUrl) {}

    std::string getData(const std::string& endpoint) {
        // Implement API data fetching
    }

private:
    std::string baseUrl;
};
