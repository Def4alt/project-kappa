#include <spdlog/spdlog.h>
#include <docopt/docopt.h>

#include <SDL2/SDL.h>

#include "Game.hpp"

#include "scenes/ColorScene.hpp"

#undef main

static constexpr auto USAGE =
	R"(Project Kappa.

    Usage:
        project_kappa [options]

 	Options:
        -h --help         Print help.
        --width=WIDTH     Width of the main window [default: 800].
        --height=HEIGHT   Height of the main window [default: 600].
)";

int main(int argc, const char **argv)
{
	std::map<std::string, docopt::value> args =
		docopt::docopt(USAGE, {std::next(argv), std::next(argv, argc)}, true,
					   "Project Kappa 1.0");

	for (auto const &arg : args)
	{
		if (arg.second.isString())
		{
			spdlog::info("Parameter set: {} '{}'", arg.first, arg.second.asString());
		}
	}

	const auto width = args["--width"].asLong();
	const auto height = args["--height"].asLong();

	auto game_params = engine::GameParams{
		"Project Kappa",
		width,
		height,
		false};

	auto *game = new engine::Game(game_params);

	game->register_scene<scene::ColorScene>("Color");

	while (game->is_running())
	{
		game->handle_events();

		game->update();
		game->render();
		game->imgui_render();

		game->swap_window();
	}

	delete game;

	return 0;
}
