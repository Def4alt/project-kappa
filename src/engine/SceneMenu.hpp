#ifndef KAPPA_ENGINE_SCENE_MENU_HPP
#define KAPPA_ENGINE_SCENE_MENU_HPP

#include "Scene.hpp"
#include <vector>
#include <functional>
#include <spdlog/spdlog.h>

namespace engine
{
    class SceneMenu : public Scene
    {
    public:
        SceneMenu(Scene *&current_test) : current_test_(current_test) {}

        void imgui_render() override;

        template <typename T>
        void register_scene(const std::string &name)
        {
            spdlog::info("Registering test {}", name);

            tests_.push_back(std::make_pair(name, []() { return new T(); }));
        }

    protected:
        engine::Scene *&current_test_;
        std::vector<std::pair<std::string, std::function<Scene *()>>> tests_;
    };
} // namespace engine

#endif // KAPPA_ENGINE_SCENE_MENU_HPP