#include "event.h"

namespace engine
{
    static bool keys_[322] = { false };

    void Event::process_events(SDL_Event *event) {
        switch (event->type) {
        case SDL_KEYDOWN:
            keys_[event->key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            keys_[event->key.keysym.sym] = false;
            break;
        default:
            break;
        }
    }

    bool Event::is_pressed(SDL_KeyCode key) {
        return keys_[key];
    }
} // namespace engine