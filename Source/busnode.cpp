#include "busnode.h"



BusNode::BusNode(MessageBus *messageBus)
{
    this->messageBus = messageBus;
    this->messageBus->addReciever(this->getNotifyFunc());
}

void BusNode::update() {};


std::function<void (Message)> BusNode::getNotifyFunc()
{
    auto messageListener = [=](Message message) -> void {
        this->onNotify(message);
    };
    return messageListener;
}

void BusNode::send(Message message)
{
    messageBus->sendMessage(message);
}

void BusNode::onNotify(Message message)
{

}
