#include <zmq.hpp>
#include <iostream>

class DistributedClient {
public:
    DistributedClient(const std::string& address) : context(1), socket(context, ZMQ_REQ) {
        socket.connect(address);
    }

    void sendCommand(const std::string& command) {
        zmq::message_t request(command.data(), command.size());
        socket.send(request, zmq::send_flags::none);

        zmq::message_t reply;
        socket.recv(reply, zmq::recv_flags::none);
        std::string response(static_cast<char*>(reply.data()), reply.size());
        std::cout << "Server replied: " << response << std::endl;
    }

private:
    zmq::context_t context;
    zmq::socket_t socket;
};
