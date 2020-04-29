#include "event-handler.h"
#include "utils.h"

using namespace util;

EventHandler::EventHandler(/* args */)
{
    bindKey(SDLK_w, "w");
    bindKey(SDLK_a, "a");
    bindKey(SDLK_s, "s");
    bindKey(SDLK_d, "d");
}

EventHandler::~EventHandler()
{
}

void EventHandler::updateHandler()
{
    if(SDL_PollEvent(&windowEvent)) {
        // any quit event created
        if(windowEvent.type == SDL_QUIT) {
            applicationEnded = true;
        }

        // keydown event
        if(windowEvent.type == SDL_KEYDOWN) {
            keyboardInputs(true);
        }
        // keyup event
        if(windowEvent.type == SDL_KEYUP) {
            keyboardInputs(false);
        }
    }
}

void EventHandler::bindKey(SDL_Keycode keycode, char* binding)
{
    keymap[keycode] = binding;
    keyTriggerMap[keycode] = false;
}

void EventHandler::keyboardInputs(bool isKeyDown)
{
    SDL_Keycode key = windowEvent.key.keysym.sym;
    keymapIterator = keymap.find(key);
    if (keymapIterator != keymap.end()) {
        keyTriggerMap[key] = isKeyDown;
    }
}

void EventHandler::mouseInputs()
{

}

bool EventHandler::isApplicationEnded()
{
    return applicationEnded;
}

void EventHandler::displayKeys()
{
    print("----------");
    for (keyTriggerIterator = keyTriggerMap.begin();  keyTriggerIterator != keyTriggerMap.end(); keyTriggerIterator++) {
        std::cout << keymap[keyTriggerIterator->first] << ": " << keyTriggerIterator->second << std::endl;
    }
    print("----------");
}
