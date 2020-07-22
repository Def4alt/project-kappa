#ifndef PROJECT_KAPPA_SCENE_H
#define PROJECT_KAPPA_SCENE_H

#include <SDL.h>

namespace scene {
    class Scene {
    public:
        Scene() {}
        virtual ~Scene() {}

        virtual void update(float delta_time) {}
        virtual void render() {}
        virtual void imgui_render() {}
    };
}


#endif //PROJECT_KAPPA_SCENE_H
