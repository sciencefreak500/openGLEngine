#include "event-handler.h"
#include "utils.h"

#include <glm/glm.hpp>
#include "camera.h"

using namespace util;

EventHandler::EventHandler()
{
    // bindKey(SDLK_w, &Camera::moveForward);
    // bindKey(SDLK_a, &Camera::moveLeft);
    // bindKey(SDLK_s, &Camera::moveBackward);
    // bindKey(SDLK_d, &Camera::moveRight);
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

        if(windowEvent.type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&mouseX, &mouseY);
            handleMousePosition();
        }

        triggerBoundFunctions();
    }
}

void EventHandler::bindKey(SDL_Keycode keycode, classFuncPtr binding)
{
    keymap[keycode] = binding;
    keyTriggerMap[keycode] = false;
}

void EventHandler::keyboardInputs(bool isKeyDown)
{
    SDL_Keycode key = windowEvent.key.keysym.sym;
    if(key == SDLK_ESCAPE) {
        applicationEnded = true;
    }
    keymapIterator = keymap.find(key);
    if (keymapIterator != keymap.end()) {
        keyTriggerMap[key] = isKeyDown;
    }
}

void EventHandler::triggerBoundFunctions()
{
    std::map<SDL_Keycode,bool>::iterator i;
    for (i = keyTriggerMap.begin(); i != keyTriggerMap.end(); i++)
    {
        if(i->second == true) {
            print(i->first);
            // classFuncPtr func = keymap[i->first];
            // func();
        }
    }
    
}

void EventHandler::mouseInputs()
{

}

void EventHandler::handleMousePosition()
{    
    SDL_GetWindowSize(window, &w, &h);
    SDL_WarpMouseInWindow(window, w/2, h/2);
}

bool EventHandler::isApplicationEnded()
{
    return applicationEnded;
}

void EventHandler::displayKeys()
{
    print("----------");
    for (keyTriggerIterator = keyTriggerMap.begin();  keyTriggerIterator != keyTriggerMap.end(); keyTriggerIterator++) {
        print(keymap[keyTriggerIterator->first], ":", keyTriggerIterator->second);
    }
    print("----------");
}
