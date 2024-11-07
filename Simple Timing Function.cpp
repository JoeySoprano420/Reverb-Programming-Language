#include <chrono>

class PerformanceTester {
public:
    void startTiming() {
        start = std::chrono::high_resolution_clock::now();
    }

    void stopTiming() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "Operation took " << duration << " microseconds." << std::endl;
    }

private:
    std::chrono::high_resolution_clock::time_point start;
};
