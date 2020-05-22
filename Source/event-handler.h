#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <map>
#include <SDL2/SDL.h>
#include "busnode.h"

class EventHandler : public BusNode
{
private:
    SDL_Event windowEvent;
    bool applicationEnded = false;

    typedef void (*classFuncPtr)();

    std::map<SDL_Keycode, classFuncPtr> keymap;
    std::map<SDL_Keycode, classFuncPtr>::iterator keymapIterator;

    std::map<SDL_Keycode, bool> keyTriggerMap;
    std::map<SDL_Keycode,bool>::iterator keyTriggerIterator;

    void onNotify(Message message);

protected:
    

    // mouse position X and Y
    int mouseX, mouseY;

    // window width and height
    int w, h;

public:
    EventHandler(MessageBus * messageBus) : BusNode(messageBus);
    ~EventHandler();

    // update the event handler from Application
    void updateHandler();

    // bind a key to an input
    void bindKey(SDL_Keycode, classFuncPtr);

    // check keyboard for something new
    void keyboardInputs(bool isKeyDown);

    // trigger bound functions if keypressed is true
    void triggerBoundFunctions();

    //check mouse inputs for something new
    void mouseInputs();

    // calculate mouse delta, and determine if 
    // return to center screen is needed
    void handleMousePosition();

    // poll event if applications should be ended
    bool isApplicationEnded();

    void displayKeys();

    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
};




#endif