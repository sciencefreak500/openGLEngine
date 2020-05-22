#ifndef MESSAGEBUS_H
#define MESSAGEBUS_H

#include <functional>
#include <queue>
#include <vector>
#include "message.h"

class MessageBus
{
private:
    std::vector<std::function<void (Message)>> receivers;
    std::queue<Message> messages;
public:
    MessageBus(/* args */);
    ~MessageBus();

    void addReciever(std::function<void (Message)> messageReciever);
    void sendMessage(Message message);
    void notify();
};





#endif