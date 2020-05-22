#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
private:
    char * messageEvent;
public:
    Message(char * event);
    ~Message();

    char * getEvent();
};




#endif