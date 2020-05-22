#ifndef BUSNODE_H
#define BUSNODE_H

#include <iostream>
#include "messagebus.h"

class BusNode
{
public:
    BusNode(MessageBus *messageBus);
    ~BusNode();

    virtual void update();

protected:
    MessageBus *messageBus;
    std::function<void (Message)> getNotifyFunc();
    void send(Message message);
    virtual void onNotify(Message message);
};


#endif