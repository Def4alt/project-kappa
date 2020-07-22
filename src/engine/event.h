#ifndef PROJECT_KAPPA_ENGINE_EVENT_H
#define PROJECT_KAPPA_ENGINE_EVENT_H

#include <SDL.h>

namespace engine
{
    class Event {
    public:
        static void process_events(SDL_Event *event);

        static bool is_pressed(SDL_KeyCode key);
    };
} // namespace engine


#endif // PROJECT_KAPPA_ENGINE_EVENT_H