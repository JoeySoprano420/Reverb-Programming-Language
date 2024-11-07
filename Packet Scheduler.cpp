#include <queue>
#include <unordered_map>
#include <thread>

class PacketScheduler {
public:
    void addPacket(Packet packet) {
        packets[packet.id] = packet;
        if (packet.dependencies.empty()) {
            readyQueue.push(packet);
        }
    }

    void run() {
        while (!readyQueue.empty()) {
            Packet packet = readyQueue.front();
            readyQueue.pop();

            // Run the packet in a separate thread if resources allow
            std::thread worker([packet]() { packet.execute(); });
            worker.join();

            // Mark as completed and release dependent packets
            completedPackets.insert(packet.id);
            releaseDependencies(packet.id);
        }
    }

private:
    std::unordered_map<int, Packet> packets;
    std::unordered_set<int> completedPackets;
    std::queue<Packet> readyQueue;

    void releaseDependencies(int packetId) {
        for (auto& [id, packet] : packets) {
            auto& deps = packet.dependencies;
            deps.erase(std::remove(deps.begin(), deps.end(), packetId), deps.end());
            if (deps.empty() && completedPackets.find(id) == completedPackets.end()) {
                readyQueue.push(packet);
            }
        }
    }
};
