#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <map>
#include <SDL2/SDL.h>

class EventHandler
{
private:
    SDL_Event windowEvent;
    bool applicationEnded = false;

    // mouse position X and Y
    int *mouseX, *mouseY;

    std::map<SDL_Keycode, char*> keymap;
    std::map<SDL_Keycode,char*>::iterator keymapIterator;

    std::map<SDL_Keycode, bool> keyTriggerMap;
    std::map<SDL_Keycode,bool>::iterator keyTriggerIterator;
public:
    EventHandler(/* args */);
    ~EventHandler();

    // update the event handler from Application
    void updateHandler();

    // bind a key to an input
    void bindKey(SDL_Keycode, char*);

    // check keyboard for something new
    void keyboardInputs(bool isKeyDown);

    //check mouse inputs for something new
    void mouseInputs();

    // calculate mouse delta, and determine if 
    // return to center screen is needed
    void handleMousePosition();

    // poll event if applications should be ended
    bool isApplicationEnded();

    void displayKeys();
};




#endif