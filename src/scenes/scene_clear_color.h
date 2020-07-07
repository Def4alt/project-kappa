#ifndef PROJECT_KAPPA_SCENE_CLEAR_COLOR_H
#define PROJECT_KAPPA_SCENE_CLEAR_COLOR_H

#include "scene.h"

namespace scene {
    class SceneClearColor: public Scene {
    public:
        SceneClearColor();
        ~SceneClearColor();

        void update(float delta_time) override;
        void render() override;
        void imgui_render() override;

    private:
        float color_[4];
    };
}


#endif //PROJECT_KAPPA_SCENE_CLEAR_COLOR_H
