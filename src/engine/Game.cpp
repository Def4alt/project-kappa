#include "Game.hpp"

#include <gl/glew.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl3.h>
#include <spdlog/spdlog.h>

namespace engine
{
    Game::Game(GameParams params) : is_running_(true)
    {
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            spdlog::error("SDL failed to initialize");
            abort();
        }

        unsigned int flags = SDL_WINDOW_OPENGL;

        if (params.fullscreen)
            flags = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;

        window_ = SDL_CreateWindow(params.title, SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, params.width, params.height,
                                   flags);

        if (window_ == NULL)
        {
            spdlog::error("Could not create window: {}", SDL_GetError());
            abort();
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        context_ = SDL_GL_CreateContext(window_);

        if (glewInit() != GLEW_OK)
        {
            spdlog::error("Failed to init GLEW");
            abort();
        }

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(window_, context_);
        ImGui_ImplOpenGL3_Init((char *)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));

        spdlog::info("Running");

        current_test_ = nullptr;
        test_menu_ = new SceneMenu(current_test_);
        current_test_ = test_menu_;
    }

    Game::~Game()
    {
        if (current_test_ != test_menu_)
            delete test_menu_;

        delete current_test_;

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        SDL_GL_DeleteContext(context_);
        SDL_DestroyWindow(window_);

        SDL_Quit();

        spdlog::info("Cleaned");
    }

    void Game::handle_events()
    {
        ImGui_ImplSDL2_ProcessEvent(&event_);

        while (SDL_PollEvent(&event_))
        {
            if (event_.type == SDL_QUIT)
            {
                is_running_ = false;
            }
        }
    }

    void Game::render()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        if (current_test_)
            current_test_->render();
    }

    void Game::imgui_render()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window_);
        ImGui::NewFrame();

        if (current_test_)
        {
            if (current_test_ != test_menu_ && ImGui::Button("<-"))
            {
                delete current_test_;
                current_test_ = test_menu_;
            }

            current_test_->imgui_render();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void Game::update()
    {
        if (current_test_)
            current_test_->update();
    }
} // namespace engine
