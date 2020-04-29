#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <map>
#include <SDL2/SDL.h>

class EventHandler
{
private:
    SDL_Event windowEvent;
    bool applicationEnded = false;

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

    // poll event if applications should be ended
    bool isApplicationEnded();

    void displayKeys();
};




#endif