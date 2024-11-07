class ExecutionEngine {
public:
    void addPacket(Packet packet) {
        scheduler.addPacket(packet);
    }

    void execute() {
        scheduler.run();
    }

private:
    PacketScheduler scheduler;
};
