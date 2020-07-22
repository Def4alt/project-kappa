#ifndef PROJECT_KAPPA_GAME_H
#define PROJECT_KAPPA_GAME_H


#include "scenes/scene.h"
#include "scenes/scene_menu.h"

class Game {
public:
    Game(const char* title, const int x, const int y, const int width, const int height, bool fullscreen);
    ~Game();

    void handle_events();
    void update(float delta_time);
    void render();
    void imgui_render();
    void swap_window();

    bool is_running;


private:
    scene::Scene* current_test_;
    scene::SceneMenu* test_menu_;

    SDL_GLContext context_;
    SDL_Window* window_;
};


#endif //PROJECT_KAPPA_GAME_H
