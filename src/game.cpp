#include <SDL.h>
#include <GL/glew.h>
#include "game.h"
#include "debug.h"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>
#include "scenes/scene_texture_2d.h"
#include "scenes/scene_batch_rendering.h"
#include "scenes/scene_clear_color.h"
#include "renderer.h"

Game::Game(const char *title, const int x, const int y, const int width, const int height, bool fullscreen) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SPDLOG_CRITICAL("SDL failed to initialize");
        return;
    }

    unsigned flags = SDL_WINDOW_OPENGL;
    if (fullscreen)
        flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;

    window_ = SDL_CreateWindow(title, x, y, width, height, flags);

    if (!window_) {
        SPDLOG_CRITICAL("Failed to create window");
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    context_ = SDL_GL_CreateContext(window_);

    if (glewInit() != GLEW_OK)
    {
        SPDLOG_CRITICAL("Failed to init GLEW");
        return;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForOpenGL(window_, context_);
    ImGui_ImplOpenGL3_Init((char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

    engine::Debug::enable_gl_debugging();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    current_test_ = nullptr;
    test_menu_ = new scene::SceneMenu(current_test_);
    current_test_ = test_menu_;

    test_menu_->RegisterTest<scene::SceneClearColor>("Clear Color");
    test_menu_->RegisterTest<scene::SceneTexture2D>("Texture 2D");
    test_menu_->RegisterTest<scene::SceneBatchRendering>("Batch Rendering");

    is_running = true;

    SPDLOG_INFO("Running");

    SPDLOG_INFO(glGetString(GL_VERSION));
}

Game::~Game() {
    if (current_test_ != test_menu_)
        delete test_menu_;

    delete current_test_;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(context_);
    SDL_DestroyWindow(window_);

    SDL_Quit();

    SPDLOG_INFO("Cleaned");
}

void Game::handle_events() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL2_ProcessEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_KEYDOWN:
                keys_[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                keys_[event.key.keysym.sym] = false;
                break;
            default:
                break;
        }
    }

    if (keys_[SDLK_ESCAPE])
        is_running = false;
}

void Game::update(float delta_time) {
    if (current_test_)
        current_test_->update(delta_time);

    SPDLOG_INFO(delta_time);
}

void Game::render() {
    const engine::Renderer renderer;
    renderer.clear();

    if (current_test_)
        current_test_->render();
}

void Game::imgui_render() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window_);
    ImGui::NewFrame();

    if (current_test_) {
        if (current_test_ != test_menu_ && ImGui::Button("<-")) {
            delete current_test_;
            current_test_ = test_menu_;
        }

        current_test_->imgui_render();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Game::swap_window() {
    SDL_GL_SwapWindow(window_);
}
