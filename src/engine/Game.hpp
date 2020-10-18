#ifndef KAPPA_ENGINE_GAME_HPP
#define KAPPA_ENGINE_GAME_HPP

#include <SDL2/SDL.h>
#include "Scene.hpp"
#include "SceneMenu.hpp"

namespace engine
{
	struct GameParams
	{
		const char *title;
		const int width;
		const int height;
		bool fullscreen;
	};

	class Game
	{
	public:
		Game(GameParams params);
		~Game();

		void handle_events();
		void update();
		void render();
		void imgui_render();
		auto swap_window() const { SDL_GL_SwapWindow(window_); }

		[[nodiscard]] constexpr auto is_running() const noexcept
		{
			return is_running_;
		};

		template <typename T>
		auto register_scene(const std::string &title) const
		{
			test_menu_->register_scene<T>(title);
		}

	protected:
		bool is_running_;

		Scene *current_test_;
		SceneMenu *test_menu_;

		SDL_Window *window_;
		SDL_GLContext context_;
		SDL_Event event_;
	};

} // namespace engine

#endif // KAPPA_ENGINE_GAME_HPP