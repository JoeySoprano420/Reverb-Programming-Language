void ThreadPool::enqueueWithPriority(Task task, Priority priority) {
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        // Insert task into a priority queue instead of a regular queue
        taskQueue.push(std::make_pair(priority, task));
    }
    condition.notify_one();
}
