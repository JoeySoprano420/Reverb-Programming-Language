#include <gtest/gtest.h>
#include "ThreadPool.h" // Assuming your thread pool is defined in this header

TEST(ThreadPoolTest, TaskExecution) {
    ThreadPool pool(4); // Create a thread pool with 4 threads
    std::atomic<int> counter(0);

    for (int i = 0; i < 100; ++i) {
        pool.enqueue([&counter] {
            counter++;
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait for tasks to finish
    EXPECT_EQ(counter.load(), 100); // Ensure all tasks were executed
}
