#include <string>
#include <vector>
#include <functional>

struct Packet {
    int id;                                 // Unique packet identifier
    std::string operation;                  // The operation this packet represents
    std::vector<int> dependencies;          // IDs of packets that must execute before this one
    std::function<void()> execute;          // Function pointer to the packet's action
};
