#include <zmq.hpp>
#include <iostream>

class DistributedServer {
public:
    DistributedServer(const std::string& address) : context(1), socket(context, ZMQ_REP) {
        socket.bind(address);
    }

    void run() {
        while (true) {
            zmq::message_t request;
            socket.recv(&request);
            std::string command(static_cast<char*>(request.data()), request.size());

            std::cout << "Received command: " << command << std::endl;

            // Process command (could include threading or direct execution)
            std::string response = "Processed: " + command;
            socket.send(zmq::message_t(response.data(), response.size()), zmq::send_flags::none);
        }
    }

private:
    zmq::context_t context;
    zmq::socket_t socket;
};
