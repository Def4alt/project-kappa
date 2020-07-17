#define IMGUI_IMPL_OPENGL_LOADER_GLEW

#include <SDL.h>
#include <imgui/imgui.h>
#include "logger.h"
#include "game.h"

#undef main

int main() {
    logger::Logger::init();

    auto *game =
            new Game("Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    800, 600, false);

    while (game->is_running) {
        game->handle_events();

        game->update(1000 / ImGui::GetIO().Framerate);
        game->render();
        game->imgui_render();
        
        game->swap_window();
    }

    delete game;

    return 0;
}
