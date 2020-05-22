#include "message.h"


Message::Message(char * event)
{
    messageEvent = event;
}

Message::~Message()
{
}

char * Message::getEvent()
{
    return messageEvent;
}