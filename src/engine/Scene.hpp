#ifndef KAPPA_ENGINE_SCENE_HPP
#define KAPPA_ENGINE_SCENE_HPP

namespace engine
{
    class Scene
    {
    public:
        Scene() {}
        virtual ~Scene() {}

        virtual void update() {}
        virtual void render() {}
        virtual void imgui_render() {}
    };

} // namespace engine

#endif // KAPPA_ENGINE_SCENE_HPP