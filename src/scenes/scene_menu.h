#ifndef PROJECT_KAPPA_SCENE_MENU_H
#define PROJECT_KAPPA_SCENE_MENU_H

#include <vector>
#include <functional>
#include "scene.h"
#include "logger.h"

namespace scene {
    class SceneMenu: public Scene {
    public:
        SceneMenu(Scene*& current_test);

        void imgui_render() override;

        template<typename T>
        void RegisterTest(const std::string& name)
        {
            logger::log(INFO, "Registering test " + name);

            tests_.push_back(std::make_pair(name, []() { return new T(); }));
        }

    private:
        Scene*& current_test_;
        std::vector<std::pair<std::string, std::function<Scene*()>>> tests_;
    };
}


#endif //PROJECT_KAPPA_SCENE_MENU_H
